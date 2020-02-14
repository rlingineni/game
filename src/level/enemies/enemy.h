#ifndef ENEMY
#define ENEMY

#include "game_item.h"
#include "renderer.h"

class Enemy : public GameItem
{
public:
  Enemy(Renderer*);
  ~Enemy();
  void update();
  void draw();
};

#endif
