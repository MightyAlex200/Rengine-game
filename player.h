#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"

class Player : public Entity{
public:
  Player(int x, int y, int width, int height);
  void draw(sf::RenderWindow* window);
  void update();
  sf::RectangleShape* shape;
  std::vector<Entity> bullets;
  float walkspeed = 0.02;
};

#endif /* end of include guard: PLAYER_H_ */
