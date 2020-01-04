#ifndef SLIDE_MANAGER
#define SLIDE_MANAGER

#include "item_manager.h"

class SlideManager : public ItemManager
{
public:
  SlideManager(Renderer*);
  ~SlideManager();
  void update();
  void draw();
};

#endif
