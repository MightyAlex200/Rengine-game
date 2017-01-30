#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Audio.hpp>
#include "entity.h"
#include "bullet.h"

class Player : public Entity{
public:
  Player(int x, int y);
  void draw(sf::RenderWindow* window);
  void update();
  sf::RectangleShape* shape;
  std::vector<Bullet*> bullets;
  sf::Clock bulletClock;
  float walkspeed = 0.1;
  sf::SoundBuffer shootSoundBuffer;
  sf::Sound shootSound;
};

#endif /* end of include guard: PLAYER_H_ */
