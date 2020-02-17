#include "label.h"

Label::Label(Renderer* ren, SDL_Rect sRect, SDL_Rect dRect) : GameItem(ren)
{
  srcRect = sRect;
  destRect = dRect;
}

Label::~Label()
{

}

void Label::update()
{

}
