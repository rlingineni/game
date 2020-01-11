#include "menu_manager.h"
#include "level_select_manager.h"

MenuManager::MenuManager(Renderer* ren) : ItemManager(ren)
{
  LevelSelectManager* levelSelectM = new LevelSelectManager(ren);
  objects.push_back(levelSelectM);
}

MenuManager::~MenuManager()
{

}
