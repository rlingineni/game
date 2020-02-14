#include "cutscene_manager.h"
#include "renderer.h"
#include "game_states.h"
#include "game.h"
#include "constants.h"

CutSceneManager::CutSceneManager(Renderer* ren) : ItemManager(ren)
{

}

CutSceneManager::~CutSceneManager()
{

}

void CutSceneManager::update()
{
  if (GameStates::getState() == GameState::LEVEL && Game::levelInfo.cutScene)
  {
    int dest = Game::levelInfo.maxHeight - WINDOW_HEIGHT + 16;
    if (Game::camera.y != dest)
      Game::camera.y += (dest - Game::camera.y) / 8 > -1 ? -1 : (dest - Game::camera.y) / 8;
    else
    {
      Game::levelInfo.cutSceneOver = true;
      Game::levelInfo.cutScene = false;
    }
  }
}
