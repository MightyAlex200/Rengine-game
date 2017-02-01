#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include "player.h"
#include "enemy.h"

#define LOG(x) std::cout << x << std::endl;

using namespace sf;

int main(){

  RenderWindow mainwindow(VideoMode(640,480), "Rengine");

  Texture playerTexture;
  playerTexture.loadFromFile("player.png");
  Player myPlayer(295,430);
  myPlayer.shape->setTexture(&playerTexture);

  Clock enemyClock;

  std::vector<Enemy*> enemies;
  SoundBuffer dieSoundBuffer;
  dieSoundBuffer.loadFromFile("explosion.wav");
  Texture enemyTexture;
  enemyTexture.loadFromFile("enemy.png");

  Sound debugSound;
  debugSound.setBuffer(dieSoundBuffer);

  Texture bgTexture;
  bgTexture.loadFromFile("background.png");
  RectangleShape background(Vector2f(640,480));
  background.setTexture(&bgTexture);

  while(mainwindow.isOpen()){
    Event e;
    while(mainwindow.pollEvent(e)){
      switch(e.type){
        case Event::Closed:
          mainwindow.close();
          break;

        default:
          break;
      }
    }

    if(Keyboard::isKeyPressed(Keyboard::E)){
      //debugSound.play();
    }

    if(enemyClock.getElapsedTime().asSeconds() > .5){
      Enemy* e = new Enemy(0,0,dieSoundBuffer);
      e->shape->setPosition(rand()%590,0);
      e->shape->setTexture(&enemyTexture);
      e->dieSound.setBuffer(dieSoundBuffer);
      enemies.push_back(e);
      enemyClock.restart();
    }

    myPlayer.update();
    for(Enemy* e : enemies){
      e->update(myPlayer.bullets, enemies);
    }

    mainwindow.clear();
    mainwindow.draw(background);
    myPlayer.draw(&mainwindow);
    for(Enemy* e : enemies){
      e->draw(&mainwindow);
    }
    mainwindow.display();

  }

  return 0;
}
