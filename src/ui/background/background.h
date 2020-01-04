#ifndef BACKGROUND
#define BACKGROUND

#include "game_item.h"
#include <SDL2/SDL.h>

class Background : public GameItem
{
public:
  Background(Renderer*, const char* imagePath, SDL_Rect destRect, int speed);
  ~Background();

  void update();
  void draw();
private:
  int speed;
};

#endif
