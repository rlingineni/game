#include "enemy.h"
#include "renderer.h"

Enemy::Enemy(Renderer* ren) : GameItem(ren)
{
  destRect = {128, 128, 800, 800};
}

Enemy::~Enemy()
{

}

void Enemy::update()
{

}

void Enemy::draw()
{
  renderer->fillRect(&destRect);
}
