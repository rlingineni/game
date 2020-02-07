#ifndef PLAYER_MANAGER
#define PLAYER_MANAGER

#include "item_manager.h"
#include "renderer.h"
#include "player.h"

class PlayerManager : public ItemManager
{
public:
  PlayerManager(Renderer*);
  ~PlayerManager();
  Player* getPlayer();
  void update();
  void draw();
private:
  bool playerActive;
};

#endif
