#include "boss_manager.h"
#include "game_states.h"
#include "game.h"
#include "boss.h"

BossManager::BossManager(Renderer* ren, Player* p) : ItemManager(ren)
{
  player = p;
}

BossManager::~BossManager()
{

}

void BossManager::update()
{
  if (GameStates::getFirstTick())
  {
    removeObjects();
  }

  if (GameStates::getState() == GameState::LEVEL)
  {
    if (Game::levelInfo.cutScene && objects.size() < 1)
    {
      objects.push_back(new Boss(renderer, player));
    }
  }

  ItemManager::update();
}
