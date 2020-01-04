#ifndef MANAGER
#define MANAGER

#include <vector>
#include "game_object.h"

class Manager : public GameObject
{
public:
  virtual void update();
  virtual void draw();
  std::vector<GameObject*> getObjects();
protected:
  Manager();
  ~Manager();

  void removeObjects();
  std::vector<GameObject*> objects;
};

#endif
