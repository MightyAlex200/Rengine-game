#ifndef ENEMY_H_
#define ENEMY_H_

#include "entity.h"

class Enemy : public Entity{
public:
  Enemy(int x, int y);
  sf::RectangleShape* shape;
  void draw(sf::RenderWindow* window);
  void update();
};

#endif /* end of include guard: ENEMY_H_ */
