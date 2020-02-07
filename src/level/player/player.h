#ifndef PLAYER
#define PLAYER

#include "game_item.h"
#include "renderer.h"
#include <SDL2/SDL.h>

class Player : public GameItem
{
public:
  Player(Renderer*);
  ~Player();
  void update();
  void draw();
  SDL_Rect getPos();
  SDL_Rect getDelta();
  void setPos(int x, int y);
private:
  SDL_Rect delta;
  float yVel, xVel;
  bool jumping, canJump;
};

#endif
