#ifndef LABEL
#define LABEL

#include "game_item.h"
#include "renderer.h"
#include "SDL.h" 

class Label : public GameItem
{
public:
  Label(Renderer*, SDL_Rect sRect, SDL_Rect dRect);
  ~Label();
  void update();
};

#endif
