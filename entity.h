#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>

class Entity{
public:
  void update();
  void draw(sf::RenderWindow* window);
};

#endif /* end of include guard: ENTITY_H_ */
