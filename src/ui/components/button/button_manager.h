#ifndef BUTTON_MANAGER
#define BUTTON_MANAGER

#include "item_manager.h"
#include "renderer.h"

class ButtonManager : public ItemManager
{
public:
  ButtonManager(Renderer*);
  ~ButtonManager();
  void update();
};

#endif
