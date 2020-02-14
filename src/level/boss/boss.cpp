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
      if (ticks % 4 == 0)
        health--;

      if (health == 0)
        GameStates::changeState(GameState::WIN);
    }
    else
    {

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
