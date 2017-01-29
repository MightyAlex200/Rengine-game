#ifndef BULLET_H_
#define BULLET_H_

#include "entity.h"

class Bullet : public Entity {
public:
  Bullet(int const x, int const y);
  void draw(sf::RenderWindow* window);
  void update();
  sf::RectangleShape* shape;
  float speed = .2;
};

#endif /* end of include guard: BULLET_H_ */
