#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#define LOG(x) std::cout << x << std::endl;

using namespace sf;

int main(){

  RenderWindow mainwindow(VideoMode(640,480), "Rengine");

  std::vector<RectangleShape*> objects;

  RectangleShape* player = new RectangleShape(Vector2f(50,50));
  float walkspeed = 0.02;

  objects.push_back(player);

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

    if(Keyboard::isKeyPressed(Keyboard::Right)){
      player->move(walkspeed,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::Left)){
      player->move(-walkspeed,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::Up)){
      player->move(0,-walkspeed);
    }
    if(Keyboard::isKeyPressed(Keyboard::Down)){
      player->move(0,walkspeed);
    }

    mainwindow.clear();

    for(RectangleShape* s : objects){
      mainwindow.draw(*s);
    }

    mainwindow.display();

  }

  return 0;
}
