#include "enemy.h"
#include <iostream>

Enemy::Enemy(int x, int y, sf::SoundBuffer& dieSoundBuffer){
  shape = new sf::RectangleShape(sf::Vector2f(50,50));
  shape->setPosition(x,y);
  shape->setFillColor(sf::Color::Blue);
  // dieSoundBuffer.loadFromFile("explosion.wav");
  dieSound.setBuffer(dieSoundBuffer);
}

void Enemy::draw(sf::RenderWindow* window){
  window->draw(*shape);
}

void Enemy::update(std::vector<Bullet*> bullets, std::vector<Enemy*>& enemies){
  shape->move(0,speed);
  if(shape->getPosition().y >= 480){
    enemies.erase(std::remove(enemies.begin(), enemies.end(), this), enemies.end());
    delete this;
  }
  for(Bullet* b : bullets){
    if(shape->getGlobalBounds().intersects(b->shape->getGlobalBounds())){ // If colliding with bullet
      enemies.erase(std::remove(enemies.begin(), enemies.end(), this), enemies.end());
      dieSound.play();
      break;
    }
  }
}
