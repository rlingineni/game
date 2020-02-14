#include "manager_manager.h"
#include "background_manager.h"
#include "slide_manager.h"
#include "menu_manager.h"
#include "component_manager.h"
#include "trampoline_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"

/*
 * It updates in the order here,
 * but draws in the reverse order
 */

ManagerManager::ManagerManager(Renderer* renderer)
{
  objects.reserve(6);

  PlayerManager* playerM = new PlayerManager(renderer);
  objects.push_back(playerM);

  EnemyManager* enemyM = new EnemyManager(renderer);
  objects.push_back(enemyM);

  TrampolineManager* trampolineM = new TrampolineManager(renderer, playerM->getPlayer());
  objects.push_back(trampolineM);

  ComponentManager* componentM = new ComponentManager(renderer);
  objects.push_back(componentM);

  MenuManager* menuM = new MenuManager(renderer);
  objects.push_back(menuM);

  SlideManager* slideM = new SlideManager(renderer);
  objects.push_back(slideM);

  BackgroundManager* backgroundM = new BackgroundManager(renderer);
  objects.push_back(backgroundM);
}

ManagerManager::~ManagerManager()
{

}

void ManagerManager::draw()
{
  for (int i = objects.size() - 1; i >= 0; i--)
  {
    objects[i]->draw();
  }
}
