#ifndef TRAMPOLINE_MANAGER
#define TRAMPOLINE_MANAGER

#include "item_manager.h"
#include "renderer.h"
#include "player.h"

class TrampolineManager : public ItemManager
{
public:
  TrampolineManager(Renderer*, Player*);
  ~TrampolineManager();
  void update();
private:
  Player* player;
};

#endif
