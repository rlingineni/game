#include "number.h"
#include "renderer.h"
#include "game_states.h"
#include "game.h"
#include <cmath>

#include <iostream>

Number::Number(Renderer* ren, Texture* text, int x, int y, int pos) : GameItem(ren)
{
  if (GameStates::getState() == GameState::LEVEL)
    destRect = {x, y, 16, 18};
  else
    destRect = {x, y, 64, 72};
  position = pos;
  texture = text;
}

Number::~Number()
{

}

void Number::update()
{
  switch (GameStates::getState())
  {
    case GameState::LEVEL:
    {
      setSrc();

      break;
    }
    case GameState::OVER:
    {
      break;
    }
    case GameState::WIN:
    {
      setSrc();

      break;
    }
  }
}

void Number::setSrc()
{
  int time = Game::levelInfo.time;
  int digits = 0;
  while (time != 0)
  {
    time /= 10;
    digits++;
  }
  if (digits == 0)
    digits = 1;
  int place = 0;
  place = (int) (log10(pow(pow(10, digits - 1), 1.0 / position)) + 1);
  int digit = (int) (Game::levelInfo.time / pow(10, place - 1)) % 10;
  srcRect = {16 * (digit % 4), 18 * (digit / 4), 16, 18};
}

void Number::draw()
{
  renderer->copy(texture->getTexture(), &srcRect, &destRect);
}
