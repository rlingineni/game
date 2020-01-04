#include "manager_manager.h"
#include "background_manager.h"
#include "slide_manager.h"
#include "component_manager.h"

ManagerManager::ManagerManager(Renderer* renderer)
{
  BackgroundManager* backgroundM = new BackgroundManager(renderer);
  objects.push_back(backgroundM);
  SlideManager* slideM = new SlideManager(renderer);
  objects.push_back(slideM);
  ComponentManager* componentM = new ComponentManager(renderer);
  objects.push_back(componentM);
}

ManagerManager::~ManagerManager()
{

}
