#ifndef TRAMPOLINE_MANAGER
#define TRAMPOLINE_MANAGER

#include "item_manager.h"
#include "renderer.h"
#include "player.h"
#include "trampoline.h"
#include <deque>

class TrampolineManager : public ItemManager
{
public:
  TrampolineManager(Renderer*, Player*);
  ~TrampolineManager();
  void update();
  void draw();
  void removeObjects();
private:
  Player* player;
  int lastTrampY;
  bool maxReached;
  std::deque<Trampoline*> objects;
};

#endif
