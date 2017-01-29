#include "enemy.h"

Enemy::Enemy(int x, int y){
  shape = new sf::RectangleShape(sf::Vector2f(50,50));
  shape->setPosition(x,y);
  shape->setFillColor(sf::Color::Blue);
}

void Enemy::draw(sf::RenderWindow* window){
  window->draw(*shape);
}

void Enemy::update(){

}
