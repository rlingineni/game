#ifndef DIALOG
#define DIALOG

#include "game_item.h"
#include "renderer.h"
#include "texture.h"

class Dialog : public GameItem
{
public:
  Dialog(Renderer*, Texture*, int srcX, int srcY, int destY);
  ~Dialog();
  void update();
  void draw();
private:
  Texture* myTexture;
};

#endif
