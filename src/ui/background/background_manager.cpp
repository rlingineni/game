#include "background_manager.h"
#include "background.h"
#include "game_states.h"
#include "constants.h"

BackgroundManager::BackgroundManager(Renderer* ren) : ItemManager(ren)
{

}

BackgroundManager::~BackgroundManager()
{

}

void BackgroundManager::update()
{
  if (GameStates::getState() == GameState::HOME)
  {
    if (GameStates::getFirstTick())
    {
      removeObjects();

      Background* b = new Background(renderer, "res/images/home.jpg", {0, 0, 1680, 900}, 0);
      objects.push_back(b);
    }
    else
    {

    }
  }
}
