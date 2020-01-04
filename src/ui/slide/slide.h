#ifndef SLIDE
#define SLIDE

#include "game_item.h"

class Slide : public GameItem
{
public:
  Slide(Renderer*, const char* imagePath);
  ~Slide();

  void update();
  void draw();
};

#endif
