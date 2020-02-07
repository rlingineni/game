#include "trampoline_manager.h"
#include "game_states.h"
#include "constants.h"
#include "trampoline.h"

TrampolineManager::TrampolineManager(Renderer* ren, Player* p) : ItemManager(ren)
{
  player = p;
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
        Trampoline* t = new Trampoline(renderer, player, 0, WINDOW_HEIGHT - 48, WINDOW_WIDTH);
        objects.push_back(t);
      }
      break;
    }
  }

  ItemManager::update();
}
