#include "item_manager.h"

ItemManager::ItemManager(Renderer* ren)
{
  renderer = ren;
}

ItemManager::~ItemManager()
{

}

void ItemManager::update()
{
  Manager::update();
}

void ItemManager::draw()
{
  Manager::draw();
}
