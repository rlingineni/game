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
  if (GameStates::getFirstTick())
  {
    removeObjects();
    switch (GameStates::getState())
    {
      case GameState::HOME:
      {
        Background* b = new Background(renderer, "res/images/home.jpg", {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, 0);
        objects.push_back(b);
        break;
      }
      case GameState::MENU:
      {
        Background* b;
        b = new Background(renderer, "res/images/menu/level_select.png", {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 2}, 0);
        objects.push_back(b);
        b = new Background(renderer, "res/images/menu/shop.jpg", {0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2}, 0);
        objects.push_back(b);
      }
    }
  }
}
