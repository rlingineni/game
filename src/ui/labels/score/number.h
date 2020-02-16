#ifndef NUMBER
#define NUMBER

#include "game_item.h"
#include "renderer.h"
#include "texture.h"

class Number : public GameItem
{
public:
  Number(Renderer*, Texture*, int x, int y, int pos);
  ~Number();
  void update();
  void draw();
private:
  void setSrc();
  int position;
  Texture* texture;
};

#endif
