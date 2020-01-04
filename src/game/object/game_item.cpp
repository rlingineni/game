#include "game_item.h"
#include "texture.h"
#include "game.h"


GameItem::GameItem(Renderer* ren)
{
  renderer = ren;
  texture = Game::getTexture();
  // Initalize rects in case not initialized
  srcRect = {0, 0, 0, 0};
  destRect = {0, 0, 0, 0};
}

GameItem::~GameItem()
{

}

void GameItem::draw()
{
  SDL_Rect renderRect = {destRect.x, destRect.y, destRect.w, destRect.h};
  renderer->copy(texture->getTexture(), &srcRect, &renderRect);
}
