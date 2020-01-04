#include "button.h"
#include <SDL2/SDL.h>
#include <cmath>
#include "game.h"

Button::Button(Renderer* renderer, SDL_Rect startPos, SDL_Rect endPos, void (*clickHandler)(Button*), bool isSelected) : UIComponent(renderer)
{
  state = ButtonState::ANIMATE;
  srcRect = {0, 0, 32, 16};
  destRect = startPos;
  myPos = endPos;
  onClick = clickHandler;
  selected = isSelected;
}

void Button::update()
{
  switch (state)
  {
    case ButtonState::ANIMATE:
    {
      // Create a function for these two sections
      double xInc = (myPos.x - destRect.x) / 8.0;
      if (xInc > 0)
        xInc = std::ceil(xInc);
      else
        xInc = std::floor(xInc);
      destRect.x += xInc;

      double yInc = (myPos.y - destRect.y) / 8.0;
      if (yInc > 0)
        yInc = std::ceil(yInc);
      else
        yInc = std::floor(yInc);
      destRect.y += yInc;

      if ((destRect.x == myPos.x) && (destRect.y == myPos.y))
        state = ButtonState::NEUTRAL;

      break;
    }
    case ButtonState::NEUTRAL:
    {
      if (selected)
      {
        int range = 4;
        double compression = 0.25;
        destRect.y = myPos.y + (std::sin(compression * ticks) * range);
        if (!((destRect.x == myPos.x) && (destRect.y <= myPos.y + range && destRect.y >= myPos.y - range)))
        {
          state = ButtonState::ANIMATE;
        }
        ticks++;
      }
      break;
    }
  }
}
