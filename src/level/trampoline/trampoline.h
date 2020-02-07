#ifndef TRAMPOLINE
#define TRAMPOLINE

#include "game_item.h"
#include "renderer.h"
#include "player.h"
#include <SDL2/SDL.h>

class Trampoline : public GameItem
{
public:
  Trampoline(Renderer*, Player*, int x, int y, int w);
  ~Trampoline();
  void update();
  void draw();
private:
  static int height;
  SDL_Rect myPos;
  Player* player;
};

#endif
