#ifndef ENEMY_MANAGER
#define ENEMY_MANAGER

#include "item_manager.h"
#include "renderer.h"
#include "player.h"

class EnemyManager : public ItemManager
{
public:
  EnemyManager(Renderer*, Player*);
  ~EnemyManager();
  void update();
private:
  Player* player;
  int ticks;
};

#endif
