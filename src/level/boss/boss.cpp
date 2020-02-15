#include "boss.h"
#include "game_states.h"
#include "game.h"
#include "constants.h"
#include <SDL2/SDL.h>

Boss::Boss(Renderer* ren, Player* p) : GameItem(ren)
{

  destRect = {WINDOW_WIDTH / 2 - 256, Game::camera.y - 128 * 3, 512, 256};
  health = 20;
  player = p;
}

Boss::~Boss()
{

}

void Boss::update()
{
  if (GameStates::getState() == GameState::LEVEL)
  {
    if (Game::levelInfo.cutSceneOver)
    {
      ticks++;

      // Player collides with top
      if ((player->getDelta().y + player->getDelta().h <= destRect.y && player->getPos().y + player->getPos().h >= destRect.y) &&
          ((player->getPos().x >= destRect.x && player->getPos().x <= destRect.x + destRect.w) ||
          (player->getPos().x + player->getPos().w >= destRect.x && player->getPos().x + player->getPos().w <= destRect.x + destRect.w)))
        player->hit(0, destRect.y - (player->getPos().y + player->getPos().h));

      // Player collides with bottom
      if ((player->getDelta().y >= destRect.y + destRect.h && player->getPos().y <= destRect.y + destRect.h) &&
          ((player->getPos().x >= destRect.x && player->getPos().x <= destRect.x + destRect.w) ||
          (player->getPos().x + player->getPos().w >= destRect.x && player->getPos().x + player->getPos().w <= destRect.x + destRect.w)))
      {
        // Risky way to deal more damage
        player->hit(1, player->getPos().y - (destRect.y + destRect.h));
        health -= 2;
      }

      // Player collides with left
      if ((player->getDelta().x + player->getDelta().w <= destRect.x && player->getPos().x + player->getPos().w >= destRect.x) &&
          ((player->getPos().y >= destRect.y && player->getPos().y <= destRect.y + destRect.h) ||
          (player->getPos().y + player->getPos().h >= destRect.y && player->getPos().y + player->getPos().h <= destRect.y + destRect.h)))
      {
        if (player->isBoosting())
          health--;
        player->hit(2, (player->getPos().x + player->getPos().w) - destRect.x);
      }

      // Player collides with right
      if ((player->getDelta().x >= destRect.x + destRect.w && player->getPos().x <= destRect.x + destRect.w) &&
          ((player->getPos().y >= destRect.y && player->getPos().y <= destRect.y + destRect.h) ||
          (player->getPos().y + player->getPos().h >= destRect.y && player->getPos().y + player->getPos().h <= destRect.y + destRect.h)))
      {
        if (player->isBoosting())
          health--;
        player->hit(3, (destRect.x + destRect.w) - player->getPos().x);
      }

      if (health == 0)
        GameStates::changeState(GameState::WIN);
    }
    else
    {
      if (Game::levelInfo.cutScene)
      {
        if (destRect.y < Game::camera.y + 16)
          destRect.y += ((Game::camera.y + 16) - destRect.y) / 8;
      }
    }
  }
}

void Boss::draw()
{
  SDL_Rect dRect = {destRect.x, destRect.y - Game::camera.y, destRect.w, destRect.h};
  renderer->setDrawColor(0, 0, 0, 255);
  renderer->fillRect(&dRect);

  // Draw health
  SDL_Rect healthBar = {16, 16, (int) ((WINDOW_WIDTH / 2) * (health / 20.0)), 16};
  if (health > 10)
    renderer->setDrawColor(0x3e, 0x89, 0x48, 255);
  else if (health > 5)
    renderer->setDrawColor(0xfe, 0xea, 0x34, 255);
  else
    renderer->setDrawColor(0xe4, 0x3b, 0x44, 255);
  renderer->fillRect(&healthBar);
}
