#ifndef BACKGROUND
#define BACKGROUND

#include "game_item.h"
#include "SDL.h" 

class Background : public GameItem
{
public:
  Background(Renderer*, const char* imagePath, SDL_Rect destRect, int speed);
  ~Background();

  void update();
  void draw();
  void setXY(int x, int y);
private:
  int speed;
};

#endif
