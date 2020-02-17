#include "label_manager.h"
#include "renderer.h"
#include "score_manager.h"
#include "game_states.h"
#include "label.h"

LabelManager::LabelManager(Renderer* ren) : ItemManager(ren)
{

}

LabelManager::~LabelManager()
{

}

void LabelManager::update()
{
  if (GameStates::getFirstTick())
  {
    removeObjects();
    objects.push_back(new ScoreManager(renderer));
  }

  if (GameStates::getState() == GameState::LEVEL)
  {
    objects.push_back(new Label(renderer, {0, 96, 320, 34}, {14, 16, 320, 34})); // Player health label
    objects.push_back(new Label(renderer, {0, 130, 320, 37}, {14, 62, 320, 37})); // Time label
  }

  ItemManager::update();
}
