#include "enemy.h"
#include "renderer.h"
#include "player.h"
#include "game.h"
#include "constants.h"
#include <SDL2/SDL.h>

Enemy::Enemy(Renderer* ren, Player* p, int y) : GameItem(ren)
{
  dir = std::rand() % 2;
  player = p;
  if (dir)
    destRect = {0, y, 128, 64};
  else
    destRect = {WINDOW_WIDTH - 128, y, 128, 64};


}

Enemy::~Enemy()
{

}

void Enemy::update()
{
  // Player collides with top
  if ((player->getDelta().y + player->getDelta().h <= destRect.y && player->getPos().y + player->getPos().h >= destRect.y) &&
      ((player->getPos().x >= destRect.x && player->getPos().x <= destRect.x + destRect.w) ||
      (player->getPos().x + player->getPos().w >= destRect.x && player->getPos().x + player->getPos().w <= destRect.x + destRect.w)))
    player->hit(0, destRect.y - (player->getPos().y + player->getPos().h));

  // Player collides with bottom
  if ((player->getDelta().y >= destRect.y + destRect.h && player->getPos().y <= destRect.y + destRect.h) &&
      ((player->getPos().x >= destRect.x && player->getPos().x <= destRect.x + destRect.w) ||
      (player->getPos().x + player->getPos().w >= destRect.x && player->getPos().x + player->getPos().w <= destRect.x + destRect.w)))
    player->hit(1, player->getPos().y - (destRect.y + destRect.h));

  // Player collides with left
  if ((player->getDelta().x + player->getDelta().w <= destRect.x && player->getPos().x + player->getPos().w >= destRect.x) &&
      ((player->getPos().y >= destRect.y && player->getPos().y <= destRect.y + destRect.h) ||
      (player->getPos().y + player->getPos().h >= destRect.y && player->getPos().y + player->getPos().h <= destRect.y + destRect.h)))
    player->hit(2, (player->getPos().x + player->getPos().w) - destRect.x);

  // Player collides with right
  if ((player->getDelta().x >= destRect.x + destRect.w && player->getPos().x <= destRect.x + destRect.w) &&
      ((player->getPos().y >= destRect.y && player->getPos().y <= destRect.y + destRect.h) ||
      (player->getPos().y + player->getPos().h >= destRect.y && player->getPos().y + player->getPos().h <= destRect.y + destRect.h)))
    player->hit(3, (destRect.x + destRect.w) - player->getPos().x);

  if (dir)
    destRect.x += 2;
  else
    destRect.x -= 2;
}

void Enemy::draw()
{
  SDL_Rect dRect = {destRect.x, destRect.y - Game::camera.y, destRect.w, destRect.h};
  renderer->fillRect(&dRect);
}

bool Enemy::offScreen()
{
  if (dir)
    return (destRect.x > WINDOW_WIDTH);
  else
    return (destRect.x < 0 - destRect.w);
}
