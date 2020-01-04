#ifndef ITEM_MANAGER
#define ITEM_MANAGER

#include "manager.h"
#include "renderer.h"

class ItemManager : public Manager
{
public:
  virtual void update();
  virtual void draw();
protected:
  ItemManager(Renderer*);
  ~ItemManager();

  Renderer* renderer;
};

#endif
