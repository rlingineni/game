#ifndef LEVEL_TILE
#define LEVEL_TILE

#include "game_item.h"
#include "texture.h"

class LevelTile : public GameItem
{
public:
  LevelTile(Renderer*, const char*, bool);
  ~LevelTile();
  void update();
  void draw();
  void setXY(int, int);
  bool isSelected;
private:
  int myX, myY;
  Texture* texture;
};

#endif
