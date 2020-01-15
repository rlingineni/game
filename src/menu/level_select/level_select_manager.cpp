#include "level_select_manager.h"
#include "level_tile.h"
#include "game_states.h"
#include "game.h"
#include "constants.h"

LevelSelectManager::LevelSelectManager(Renderer* ren) : ItemManager(ren)
{
  selectedIndex = 0;
}

LevelSelectManager::~LevelSelectManager()
{

}

void LevelSelectManager::update()
{
  if (GameStates::getFirstTick())
  {
    removeObjects();
    switch (GameStates::getState())
    {
      case GameState::MENU:
      {
        LevelTile* l;
        l = new LevelTile(renderer, "res/images/menu/level_tiles/level_1.png", true);
        objects.push_back(l);
        l = new LevelTile(renderer, "res/images/menu/level_tiles/level_2.png", false);
        objects.push_back(l);
        l = new LevelTile(renderer, "res/images/menu/level_tiles/level_3.png", false);
        objects.push_back(l);
        l = new LevelTile(renderer, "res/images/menu/level_tiles/level_4.png", false);
        objects.push_back(l);
        l = new LevelTile(renderer, "res/images/menu/level_tiles/level_5.png", false);
        objects.push_back(l);
      }
    }
  }

  switch (GameStates::getState())
  {
    case GameState::MENU:
    {
      for (int i = 0; i < objects.size(); i++)
      {
        if (dynamic_cast<LevelTile*>(objects[i])->focused())
        {
          if (Game::inputs.attack)
          {
            selectedIndex = i;
            switchSelected((LevelTile*) objects[i]);
          }
        }

        dynamic_cast<LevelTile*>(objects[i])->setXY((WINDOW_WIDTH / 2 - 128) + (i * 492) - (selectedIndex * 492), 64);
      }
    }
  }

  Manager::update();
}

void LevelSelectManager::switchSelected(LevelTile* lT)
{
  for (auto tile : objects)
  {
    if ((LevelTile*) tile == lT)
      dynamic_cast<LevelTile*>(tile)->isSelected = true;
    else
      dynamic_cast<LevelTile*>(tile)->isSelected = false;
  }
}
