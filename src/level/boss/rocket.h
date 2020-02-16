#ifndef ROCKET
#define ROCKET

#include "game_item.h"
#include "renderer.h"
#include "player.h"

class Rocket : public GameItem
{
public:
  Rocket(Renderer*, Player*, int x, int y, int dir);
  ~Rocket();
  void update();
  void draw();
  bool isOffScreen();
private:
  Player* player;
  int direction; // 0 up, 1 down, 2 left, 3 right
  int yVel, xVel;
};

#endif
