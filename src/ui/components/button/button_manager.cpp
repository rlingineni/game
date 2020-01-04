#include "button_manager.h"
#include "button.h"
#include "game.h"
#include "game_states.h"
#include "constants.h"

static int buttonW = 128;
static int buttonH = 64;

ButtonManager::ButtonManager(Renderer* ren) : ItemManager(ren)
{
  selectedIndex = 0;
  switched = false;
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
      button = new Button(renderer, {(WINDOW_WIDTH / 2) - (buttonW / 2), WINDOW_HEIGHT, buttonW, buttonH}, {(WINDOW_WIDTH / 2) - (buttonW / 2), (WINDOW_HEIGHT / 2) - (buttonH / 2), buttonW, buttonH}, nullptr, true);
      objects.push_back(button);
      button = new Button(renderer, {(WINDOW_WIDTH / 2) - (buttonW / 2), WINDOW_HEIGHT, buttonW, buttonH}, {(WINDOW_WIDTH / 2) - (buttonW / 2), (WINDOW_HEIGHT / 2) - (buttonH / 2) + buttonH * 2, buttonW, buttonH}, nullptr, false);
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
      if (Game::inputs.up)
      {
        if (!switched)
        {
          if (selectedIndex == 0)
            selectedIndex = objects.size() - 1;
          else
            selectedIndex--;
          setButtonSelected(selectedIndex);
          switched = true;
        }
      }
      else if (Game::inputs.down)
      {
        if (!switched)
        {
          if (selectedIndex == objects.size() - 1)
            selectedIndex = 0;
          else
            selectedIndex++;
          setButtonSelected(selectedIndex);
          switched = true;
        }
      }
      else
      {
        switched = false;
      }
    }
  }
  Manager::update(); // Call the update of every object
}

void ButtonManager::setButtonSelected(int index)
{
  for (int i = 0; i < objects.size(); i++)
  {
    if (i == index)
      dynamic_cast<Button*>(objects[i])->selected = true;
    else
      dynamic_cast<Button*>(objects[i])->selected = false;
  }
}
