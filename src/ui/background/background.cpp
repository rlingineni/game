#include "background.h"

Background::Background(Renderer* ren, const char* imagePath, SDL_Rect rect, int speed) : GameItem(ren)
{
  texture = new Texture(imagePath, ren);
  destRect = rect;
  this->speed = speed;
}

Background::~Background()
{
  delete texture;
}

void Background::update()
{

}

void Background::draw()
{
  renderer->copy(texture->getTexture(), NULL, &destRect);
}
