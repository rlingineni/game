#ifndef LABEL_MANAGER
#define LABEL_MANAGER

#include "item_manager.h"
#include "renderer.h"

class LabelManager : public ItemManager
{
public:
  LabelManager(Renderer*);
  ~LabelManager();
};

#endif
