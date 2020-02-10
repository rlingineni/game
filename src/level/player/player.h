#ifndef PLAYER
#define PLAYER

#include "game_item.h"
#include "renderer.h"
#include <SDL2/SDL.h>
#include <deque> // Probably better options but no time

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
  int getMaxYVel();
private:
  SDL_Rect delta;
  std::deque<SDL_Rect> deltas;
  float yVel, xVel;
  bool jumping, canJump, shouldJump;
  int defMinMaxYVel, defMaxMaxYVel;
  int maxYVel, maxXVel;
  int ticks, trampTicks, airTicks;
  bool boosting, canBoost;
  int boostTicks, boostDir;
};

#endif
