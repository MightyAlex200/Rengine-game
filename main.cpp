#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "player.h"

#define LOG(x) std::cout << x << std::endl;

using namespace sf;

int main(){

  RenderWindow mainwindow(VideoMode(640,480), "Rengine");
  Player myPlayer(0,0,50,50);

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

    myPlayer.update();

    mainwindow.clear();
    myPlayer.draw(&mainwindow);
    mainwindow.display();

  }

  return 0;
}
