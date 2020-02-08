#include "player.h"
#include "constants.h"
#include "game_states.h"
#include "game.h"
#include <SDL2/SDL.h>

Player::Player(Renderer* ren) : GameItem(ren)
{
  destRect = {WINDOW_WIDTH / 2 - 32, WINDOW_HEIGHT - 64 * 6, 64, 64};
  srcRect = {0, 32, 64, 64};
  delta = destRect;
  yVel = 0;
  canJump = false;
  jumping = false;
  shouldJump = false;
  ticks = 0;
  trampTicks = 0;
  airTicks = 0;

  defMinMaxYVel = 5;
  defMaxMaxYVel = 40;
  maxYVel = defMinMaxYVel;
  maxXVel = 10;
}

Player::~Player()
{

}

void Player::update()
{
  ticks++;

  if (GameStates::getState() == GameState::LEVEL)
  {
    delta = destRect;

    if (Game::inputs.up)
    {
      if (maxYVel < defMaxMaxYVel && canJump && ticks % 2 == 0)
      {
        maxYVel += 1;
      }

      if (canJump)
      {
        trampTicks++;
      }

      shouldJump = true;
    }
    else
    {
      trampTicks = 1;
      if (shouldJump && canJump)
      {
        jumping = true;
        canJump = false;
      }
      shouldJump = false;
    }

    if (Game::inputs.left || Game::inputs.right)
    {
      if (Game::inputs.left)
      {
        if (-xVel < maxXVel)
          xVel -= 0.5;
      }
      else
      {
        if (xVel < maxXVel)
          xVel += 0.5 ;
      }
    }
    else
      xVel /= 2;

    if (!jumping)
    {
      yVel += 0.5;
      if (Game::inputs.up)
      {
        if (yVel < 0)
          yVel += 1;
        else
          yVel *= 1.1;
      }
    }
    else
    {
      if (-yVel < maxYVel)
      {
        yVel = -maxYVel - yVel / 2;
      }
      else
      {
        maxYVel = defMinMaxYVel;
        jumping = false;
      }
    }

    destRect.y += yVel;
    destRect.x += xVel;

    if (yVel > 0)
    {
      if (destRect.y + destRect.h / 2 >= Game::camera.y + WINDOW_HEIGHT - WINDOW_HEIGHT / 4)
        Game::camera.y = (destRect.y + destRect.h / 2) - WINDOW_HEIGHT + WINDOW_HEIGHT / 4;
    }
    else
    {
      if (destRect.y + destRect.h / 2 <= Game::camera.y + WINDOW_HEIGHT / 4)
      {
        Game::camera.y = (destRect.y + destRect.h / 2) - WINDOW_HEIGHT / 4;
        if (Game::camera.y < Game::levelInfo.maxHeight)
          Game::levelInfo.maxHeight = Game::camera.y;
      }
    }
  }

  airTicks++;
  if (airTicks > 2)
    canJump = false;
}

void Player::draw()
{

  if (trampTicks % (-maxYVel / 5 + 20) == 0)
    srcRect = {64, 32, 64, 64};
  else
    srcRect = {0, 32, 64, 64};
  SDL_Rect dRect = {destRect.x, (destRect.y + maxYVel / 5) - Game::camera.y, destRect.w, destRect.h};
  renderer->copy(Game::getTexture()->getTexture(), &srcRect, &dRect);
}

SDL_Rect Player::getPos()
{
  return destRect;
}

SDL_Rect Player::getDelta()
{
  return delta;
}

void Player::setPos(int x, int y)
{
  destRect.x = x;
  destRect.y = y;
  if (Game::inputs.up)
    yVel = 0;
  else
    if (yVel > 5)
      yVel = -yVel / 2;
    else
      yVel = 0;
  canJump = true;
  airTicks = 0;
}

int Player::getMaxYVel()
{
  return maxYVel;
}
