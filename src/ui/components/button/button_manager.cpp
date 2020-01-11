#include "button_manager.h"
#include "button.h"
#include "game.h"
#include "game_states.h"
#include "constants.h"

#include <SDL2/SDL.h>

static int buttonW = 128;
static int buttonH = 64;

static void quit(Button* button)
{
  GameStates::changeState(GameState::QUIT);
}

static void menu(Button* button)
{
  GameStates::changeState(GameState::MENU);
}

ButtonManager::ButtonManager(Renderer* ren) : ItemManager(ren)
{

}

ButtonManager::~ButtonManager()
{

}

void ButtonManager::update()
{
  // Handle object creation and deletion
  if (GameStates::getFirstTick())
  {
    removeObjects();
    if (GameStates::getState() == GameState::HOME)
    {
      Button* button;
      button = new Button(renderer, (WINDOW_WIDTH / 2) - (buttonW / 2), (WINDOW_HEIGHT / 2) - (buttonH / 2), buttonW, buttonH, menu);
      objects.push_back(button);
      button = new Button(renderer, (WINDOW_WIDTH / 2) - (buttonW / 2), (WINDOW_HEIGHT / 2) - (buttonH / 2) + buttonH * 2, buttonW, buttonH, quit);
      objects.push_back(button);
    }
    else if (GameStates::getState() == GameState::LEVEL)
    {

    }
    else if (GameStates::getState() == GameState::OVER)
    {

    }
  }

  switch (GameStates::getState())
  {
    case GameState::HOME:
    {

    }
  }

  Manager::update(); // Call the update of every object
}
