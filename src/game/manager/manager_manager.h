#ifndef MANAGER_MANAGER
#define MANAGER_MANAGER

#include "manager.h"
#include "renderer.h"

class ManagerManager : public Manager
{
public:
  ManagerManager(Renderer*);
  ~ManagerManager();
};

#endif
