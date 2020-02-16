#include "rocket.h"
#include "renderer.h"
#include "player.h"
#include "game.h"
#include "constants.h"
#include <SDL2/SDL.h>

static int maxVel = 10;

Rocket::Rocket(Renderer* ren, Player* p, int x, int y, int dir) : GameItem(ren)
{
  xVel = 0;
  yVel = 0;
  player = p;
  direction = dir;
  switch (direction)
  {
    case 0:
    case 1:
      destRect = {x, y, 32, 64};
      break;
    case 2:
    case 3:
      destRect = {x, y, 64, 32};
      break;
  }
}

Rocket::~Rocket()
{

}

void Rocket::update()
{
  switch (direction) {
    case 0:
      if (-yVel < maxVel)
        yVel--;
    case 1:
      if (yVel < maxVel)
        yVel++;
    case 2:
      if (-xVel < maxVel)
        xVel--;
    case 3:
      if (xVel < maxVel)
        xVel++;
  }
  destRect.x += xVel;
  destRect.y += yVel;
}

void Rocket::draw()
{
  SDL_Rect dRect = {destRect.x, destRect.y - Game::camera.y, destRect.w, destRect.h};
  renderer->setDrawColor(0, 0, 0, 255);
  renderer->fillRect(&dRect);
}

bool Rocket::isOffScreen()
{
  switch (direction)
  {
    case 0: // Up
      return destRect.y < Game::camera.y;
    case 1: // Down
      return destRect.y + destRect.h > Game::camera.y + WINDOW_HEIGHT;
    case 2: // Left
      return destRect.x < 0;
    case 3: // Right
      return destRect.x + destRect.w > WINDOW_WIDTH;
  }
  return true; // Shouldn't reach here, object should be deleted
}
