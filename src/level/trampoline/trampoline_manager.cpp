#include "trampoline_manager.h"
#include "game_states.h"
#include "game.h"
#include "constants.h"
#include "trampoline.h"
#include <cstdlib>
#include <ctime>

TrampolineManager::TrampolineManager(Renderer* ren, Player* p) : ItemManager(ren)
{
  player = p;
  std::srand(std::time(nullptr));
}

TrampolineManager::~TrampolineManager()
{

}

void TrampolineManager::update()
{
  if (GameStates::getFirstTick())
  {
    switch (GameStates::getState())
    {
      case GameState::LEVEL:
      {
        objects.push_back(new Trampoline(renderer, player, 0, WINDOW_HEIGHT - 48, WINDOW_WIDTH));
        objects.push_back(new Trampoline(renderer, player, std::rand() % WINDOW_WIDTH - (WINDOW_WIDTH / 8), WINDOW_HEIGHT / 2, std::rand() % 512 + 512));
      }
      break;
    }
  }

  if (GameStates::getState() == GameState::LEVEL)
  {
    if (lastTrampY - Game::levelInfo.maxHeight > 256)
    {
      objects.push_back(new Trampoline(renderer, player, std::rand() % WINDOW_WIDTH - (WINDOW_WIDTH / 8), Game::camera.y, std::rand() % 512 + 512));
      lastTrampY = Game::camera.y;
    }
  }

  ItemManager::update();
}
