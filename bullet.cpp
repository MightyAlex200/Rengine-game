#include "bullet.h"

Bullet::Bullet(int const x, int const y){
  shape = new sf::RectangleShape(sf::Vector2f(5,5));
  shape->setPosition(x,y);
  shape->setFillColor(sf::Color::Black);
}

void Bullet::draw(sf::RenderWindow* window){
  window->draw(*shape);
}

void Bullet::update(){
  shape->move(0,-speed);
}
