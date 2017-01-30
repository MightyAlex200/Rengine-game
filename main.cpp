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
  Player myPlayer(295,430);
  Clock enemyClock;
  std::vector<Enemy*> enemies;

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

    if(enemyClock.getElapsedTime().asSeconds() > .5){
      Enemy* e = new Enemy(0,0);
      e->shape->setPosition(rand()%640,0);
      enemies.push_back(e);
      enemyClock.restart();
    }

    myPlayer.update();
    for(Enemy* e : enemies){
      e->update(myPlayer.bullets, enemies);
    }

    mainwindow.clear();
    myPlayer.draw(&mainwindow);
    for(Enemy* e : enemies){
      e->draw(&mainwindow);
    }
    mainwindow.display();

  }

  return 0;
}
