#ifndef BACKGROUND_MANAGER
#define BACKGROUND_MANAGER

#include "item_manager.h"

class BackgroundManager : public ItemManager
{
public:
  BackgroundManager(Renderer*);
  ~BackgroundManager();
  void update();
};

#endif
