#include "trampoline.h"

int Trampoline::height = 32;

Trampoline::Trampoline(Renderer* ren, Player* p, int x, int y, int w) : GameItem(ren)
{
  myPos = {x, y, w, height};
  destRect = myPos;
  player = p;
}

Trampoline::~Trampoline()
{

}

void Trampoline::update()
{
  if (player->getDelta().y + player->getDelta().h <= myPos.y && player->getPos().y + player->getPos().h > myPos.y)
  {
    if ((player->getPos().x > myPos.x && player->getPos().x < myPos.x + myPos.w) ||
        (player->getPos().x + player->getPos().w > myPos.x && player->getPos().x + player->getPos().w < myPos.x + myPos.w))
    {
      player->setPos(player->getPos().x, myPos.y - player->getPos().h);
    }
  }
}

void Trampoline::draw()
{
  renderer->fillRect(&destRect);
}
