#ifndef BOSS
#define BOSS

#include "game_item.h"
#include "renderer.h"
#include "player.h"

class Boss : public GameItem
{
public:
  Boss(Renderer*, Player*);
  ~Boss();
  void update();
  void draw();
private:
  int health;
  Player* player;
  int ticks;
};

#endif
