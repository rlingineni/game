#ifndef UI_COMPONENT
#define UI_COMPONENT

#include <SDL2/SDL.h>
#include "game_item.h"
#include "renderer.h"

class UIComponent : public GameItem
{
public:
  UIComponent(Renderer*);

  virtual void update() = 0;
};

#endif
