#include "level_tile.h"

LevelTile::LevelTile(Renderer* ren, bool selected) : GameItem(ren)
{
  srcRect = {0, 0, 32, 16};
  destRect.w = 256;
  destRect.h = 256;
  isSelected = selected;
}

LevelTile::~LevelTile()
{

}

void LevelTile::update()
{
  if (destRect.x != myX)
    destRect.x += (myX - destRect.x) / 4;

  if (destRect.y != myY)
    destRect.y += (myY - destRect.y) / 4;
}

void LevelTile::draw()
{
  SDL_Rect renderRect = {destRect.x, destRect.y, destRect.w, destRect.h};
  if (isSelected)
    renderRect = {destRect.x - 16, destRect.y - 16, destRect.w + 32, destRect.h + 32};
  renderer->copy(texture->getTexture(), &srcRect, &renderRect);
}

void LevelTile::setXY(int x, int y)
{
  myX = x;
  myY = y;
  if (destRect.x == 0 || destRect.y == 0)
  {
    destRect.x = myX;
    destRect.y = myY;
  }

}
