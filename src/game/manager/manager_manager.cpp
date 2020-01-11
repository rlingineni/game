#include "manager_manager.h"
#include "background_manager.h"
#include "slide_manager.h"
#include "menu_manager.h"
#include "component_manager.h"

ManagerManager::ManagerManager(Renderer* renderer)
{
  objects.reserve(4);

  BackgroundManager* backgroundM = new BackgroundManager(renderer);
  objects.push_back(backgroundM);
  SlideManager* slideM = new SlideManager(renderer);
  objects.push_back(slideM);
  MenuManager* menuM = new MenuManager(renderer);
  objects.push_back(menuM);
  ComponentManager* componentM = new ComponentManager(renderer);
  objects.push_back(componentM);
}

ManagerManager::~ManagerManager()
{

}
