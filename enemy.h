#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Audio.hpp>
#include "entity.h"
#include "bullet.h"

class Enemy : public Entity{
public:
  Enemy(int x, int y, sf::SoundBuffer& dieSoundBuffer);
  sf::RectangleShape* shape;
  void draw(sf::RenderWindow* window);
  void update(std::vector<Bullet*> bullets, std::vector<Enemy*>& enemies);
  float speed = 0.05;
  // sf::SoundBuffer dieSoundBuffer;
  sf::Sound dieSound;
};

#endif /* end of include guard: ENEMY_H_ */
