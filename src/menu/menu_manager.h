#ifndef MENU_MANAGER
#define MENU_MANAGER

#include "item_manager.h"
#include "renderer.h"

class MenuManager : public ItemManager
{
public:
  MenuManager(Renderer*);
  ~MenuManager();
};

#endif
