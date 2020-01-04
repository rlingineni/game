#include "manager_manager.h"
#include "game_states.h"
#include "slide_manager.h"

ManagerManager::ManagerManager(Renderer* renderer)
{
  SlideManager* slideM = new SlideManager(renderer);
  objects.push_back(slideM);
}

ManagerManager::~ManagerManager()
{

}
