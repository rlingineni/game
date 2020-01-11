#include "button.h"
#include <SDL2/SDL.h>
#include <cmath>
#include "game.h"

Button::Button(Renderer* renderer, int x, int y, int w, int h, void (*clickHandler)(Button*)) : UIComponent(renderer)
{
  srcRect = {0, 0, 32, 16};
  myPos = {x, y, w, h};
  destRect = myPos;
  onClick = clickHandler;
  state = ButtonState::NEUTRAL;
}

void Button::update()
{
  ticks++;
  
  switch (state)
  {
    case ButtonState::NEUTRAL:
      {
        if (focused())
        {
          state = ButtonState::HOVER;
        }
        break;
    }
    case ButtonState::HOVER:
    {
      int range = 4;
      double compression = 0.25;
      destRect.y = myPos.y + (std::sin(compression * ticks) * range);

      if (Game::inputs.attack)
      {
        onClick(this);
      }
      if (!focused())
      {
        destRect = myPos;
        state = ButtonState::NEUTRAL;
      }
    }
  }
}

bool Button::focused()
{
  return (Game::inputs.mouseX >= myPos.x &&
          Game::inputs.mouseX <= myPos.x + destRect.w &&
          Game::inputs.mouseY >= myPos.y &&
          Game::inputs.mouseY <= myPos.y + destRect.h);
}

void Button::click()
{
  onClick(this);
}
