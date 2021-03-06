#include "level_select_manager.h"
#include "level_tile.h"
#include "game_states.h"
#include "game.h"
#include "constants.h"

LevelSelectManager::LevelSelectManager(Renderer* ren) : ItemManager(ren)
{

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
            Game::levelInfo.level = i;
            switchSelected(dynamic_cast<LevelTile*>(objects[i]));
          }
        }

        int arb = 512;
        dynamic_cast<LevelTile*>(objects[i])->setXY((WINDOW_WIDTH / 2 - 192) + (i * arb) - (Game::levelInfo.level * arb), WINDOW_HEIGHT / 2 - 192);
      }
    }
  }

  Manager::update();
}

void LevelSelectManager::switchSelected(LevelTile* lT)
{
  for (auto tile : objects)
  {
    if (dynamic_cast<LevelTile*>(tile) == lT)
      dynamic_cast<LevelTile*>(tile)->isSelected = true;
    else
      dynamic_cast<LevelTile*>(tile)->isSelected = false;
  }
}
