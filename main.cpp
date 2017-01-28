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
    if(Keyboard::isKeyPressed(Keyboard::Space)){
      RectangleShape* bullet = new RectangleShape(Vector2f(5,5));
      bullet->setPosition(player->getPosition()+Vector2f(22.5,22.5));
      objects.push_back(bullet);
    }

    mainwindow.clear();

    for(RectangleShape* s : objects){
      if(s->getSize() == Vector2f(5,5)){
        s->move(0,-5);
      }
      if(s->getPosition().y < 0){
        objects.erase(std::remove(objects.begin(), objects.end(), s), objects.end());;
      }else{
        mainwindow.draw(*s);
      }
    }

    mainwindow.display();

  }

  for(RectangleShape* s : objects){
    delete s;
  }

  return 0;
}
