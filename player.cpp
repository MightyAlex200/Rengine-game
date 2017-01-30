#include "player.h"

Player::Player(int x, int y){
  shape = new sf::RectangleShape(sf::Vector2f(50,50));
  shape->setPosition(sf::Vector2f(x,y));
  shootSoundBuffer.loadFromFile("shoot.wav");
  shootSound.setBuffer(shootSoundBuffer);
}

void Player::draw(sf::RenderWindow* window){
  window->draw(*shape);
  for(Bullet* b : bullets){
    b->draw(window);
  }
}

void Player::update(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    shape->move(walkspeed,0);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    shape->move(-walkspeed,0);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    shape->move(0,-walkspeed);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    shape->move(0,walkspeed);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    if(bulletClock.getElapsedTime().asSeconds() > 0.1){
      shootSound.play();
      bullets.push_back(new Bullet(shape->getPosition().x+22.5, shape->getPosition().y+22.5));
      bulletClock.restart();
    }
  }
  for(Bullet* b : bullets){
    b->update();
    if(b->shape->getPosition().y < 0){
      bullets.erase(std::remove(bullets.begin(), bullets.end(), b), bullets.end());
    }
  }
}
