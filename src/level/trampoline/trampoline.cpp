#include "trampoline.h"
#include "game.h"
#include <SDL2/SDL.h>

int Trampoline::height = 32;

Trampoline::Trampoline(Renderer* ren, Player* p, int x, int y, int w) : GameItem(ren)
{
  myPos = {x, y, w, height};
  destRect = myPos;
  player = p;
  touchingPlayer = false;
}

Trampoline::~Trampoline()
{

}

void Trampoline::update()
{
  if (touchingPlayer)
  {
    ticks++;
    if (ticks > 1)
    {
      touchingPlayer = false;
      ticks = 0;
    }
  }

  if (player->getDelta().y + player->getDelta().h <= myPos.y && player->getPos().y + player->getPos().h > myPos.y)
  {
    if ((player->getPos().x > myPos.x && player->getPos().x < myPos.x + myPos.w) ||
        (player->getPos().x + player->getPos().w > myPos.x && player->getPos().x + player->getPos().w < myPos.x + myPos.w))
    {
      player->setPos(player->getPos().x, myPos.y - player->getPos().h);
      touchingPlayer = true;
    }
  }
}

void Trampoline::draw()
{
  if (touchingPlayer)
    destRect.y = myPos.y + player->getMaxYVel() / 5;
  else
  {
    destRect.y += (myPos.y - destRect.y) / 4;
  }
  SDL_Rect dRect = destRect;
  dRect.y = dRect.y - Game::camera.y;
  renderer->fillRect(&dRect);
}
