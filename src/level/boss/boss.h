#ifndef BOSS
#define BOSS

#include "game_item.h"
#include "renderer.h"
#include "player.h"
#include "item_manager.h"

class Boss : public GameItem, public ItemManager
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
  bool dir; // True = right, False = left
};

#endif
