#ifndef ENEMY
#define ENEMY

#include "game_item.h"
#include "renderer.h"
#include "player.h"

class Enemy : public GameItem
{
public:
  Enemy(Renderer*, Player*, int y);
  ~Enemy();
  void update();
  void draw();
  bool offScreen();
private:
  Player* player;
  bool dir; // True = right, False = left
};

#endif
