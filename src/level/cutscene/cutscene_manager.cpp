#include "cutscene_manager.h"
#include "renderer.h"
#include "game_states.h"
#include "game.h"
#include "constants.h"
#include "dialog.h"
#include "game_input.h"

CutSceneManager::CutSceneManager(Renderer* ren) : ItemManager(ren)
{
  dialogTexture = new Texture("res/images/dialog/dialogs.png", renderer);
}

CutSceneManager::~CutSceneManager()
{
  delete dialogTexture;
}

void CutSceneManager::update()
{
  if (GameStates::getFirstTick() && GameStates::getState() == GameState::LEVEL)
  {
    switch (Game::levelInfo.level)
    {
      case 0:
        objects.push_back(new Dialog(renderer, dialogTexture, 0, 0, WINDOW_HEIGHT - 200));
        objects.push_back(new Dialog(renderer, dialogTexture, 0, 0, 0));
        objects.push_back(new Dialog(renderer, dialogTexture, 0, 0, WINDOW_HEIGHT - 200));
        objects.push_back(new Dialog(renderer, dialogTexture, 0, 0, 0));
        objects.push_back(new Dialog(renderer, dialogTexture, 0, 0, WINDOW_HEIGHT - 200));
        objects.push_back(new Dialog(renderer, dialogTexture, 0, 0, 0));
        objects.push_back(new Dialog(renderer, dialogTexture, 0, 0, WINDOW_HEIGHT - 200));
        objects.push_back(new Dialog(renderer, dialogTexture, 0, 0, 0));
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
    }
  }

  if (GameStates::getState() == GameState::LEVEL && Game::levelInfo.cutScene)
  {
    int dest = Game::levelInfo.maxHeight - WINDOW_HEIGHT + 16;
    if (Game::camera.y != dest)
      Game::camera.y += (dest - Game::camera.y) / 8 > -1 ? -1 : (dest - Game::camera.y) / 8;
    else if (objects.size() > 0)
    {
      if (Game::inputs.attack)
        objects.pop_back();
    }
    else
    {
      Game::levelInfo.cutSceneOver = true;
      Game::levelInfo.cutScene = false;
    }
  }
}

void CutSceneManager::draw()
{
  if (GameStates::getState() == GameState::LEVEL && Game::levelInfo.cutScene && objects.size() > 0)
    objects[objects.size() - 1]->draw();
}
