#ifndef ENEMY_MANAGER
#define ENEMY_MANAGER

#include "item_manager.h"
#include "renderer.h"

class EnemyManager : public ItemManager
{
public:
  EnemyManager(Renderer*);
  ~EnemyManager();
  void update();
};

#endif
