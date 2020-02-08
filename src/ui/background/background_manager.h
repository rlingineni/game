#ifndef BACKGROUND_MANAGER
#define BACKGROUND_MANAGER

#include "item_manager.h"
#include "mixer.h"

class BackgroundManager : public ItemManager
{
public:
  BackgroundManager(Renderer*);
  ~BackgroundManager();
  void update();
private:
  Mixer* mix;
};

#endif
