#include "manager.h"

Manager::Manager()
{

}

Manager::~Manager()
{
  removeObjects();
}

void Manager::update()
{
 for (auto obj : objects)
  obj->update();
}

void Manager::draw()
{
  for (auto obj: objects)
    obj->draw();
}

void Manager::removeObjects()
{
  for (auto obj : objects)
    delete obj;
  std::vector<GameObject*>().swap(objects);
}

std::vector<GameObject*> Manager::getObjects()
{
  return objects;
}
