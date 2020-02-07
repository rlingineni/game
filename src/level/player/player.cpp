#include "player.h"
#include "constants.h"
#include "game_states.h"
#include "game.h"

static int maxYVel = 20;
static int maxXVel = 20;

Player::Player(Renderer* ren) : GameItem(ren)
{
  destRect = {WINDOW_WIDTH / 2 - 32, WINDOW_HEIGHT - 64 * 6, 64, 64};
  delta = destRect;
  yVel = 0;
  canJump = true;
  jumping = false;
}

Player::~Player()
{

}

void Player::update()
{
  if (GameStates::getState() == GameState::LEVEL)
  {
    delta = destRect;

    if (Game::inputs.up)
    {
      if (canJump)
      {
        jumping = true;
        canJump = false;
      }
    }
    else
      jumping = false;

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
          xVel += 0.5;
      }
    }
    else
      xVel /= 2;

    if (!jumping)
    {
      if (yVel < maxYVel)
        yVel += 0.5;
    }
    else
    {
      if (-yVel < maxYVel / 2)
        yVel -= 0.5;
      else
        jumping = false;
    }

    destRect.y += yVel;
    destRect.x += xVel;
  }
}

void Player::draw()
{
  renderer->fillRect(&destRect);
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
  yVel = 0;
  canJump = true;
}
