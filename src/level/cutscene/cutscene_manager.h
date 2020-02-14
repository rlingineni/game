#ifndef CUSTSCENE_MANAGER
#define CUSTSCENE_MANAGER

#include "item_manager.h"
#include "renderer.h"

class CutSceneManager : public ItemManager
{
public:
  CutSceneManager(Renderer*);
  ~CutSceneManager();
  void update();
};

#endif
