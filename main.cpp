#include <SFML/Graphics.hpp>

using namespace sf;

int main(){

  RenderWindow mainwindow(VideoMode(640,480), "Rengine");

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

    mainwindow.clear();
    
    mainwindow.display();

  }

  return 0;
}
