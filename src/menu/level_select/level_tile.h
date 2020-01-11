#ifndef LEVEL_TILE
#define LEVEL_TILE

#include "game_item.h"

class LevelTile : public GameItem
{
public:
  LevelTile(Renderer*, bool);
  ~LevelTile();
  void update();
  void draw();
  void setXY(int, int);
  bool isSelected;
private:
  int myX, myY;
};

#endif
