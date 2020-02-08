#include "background_manager.h"
#include "background.h"
#include "game_states.h"
#include "constants.h"
#include "game.h"

BackgroundManager::BackgroundManager(Renderer* ren) : ItemManager(ren)
{
  mix = new Mixer();
  mix->addTrack("res/music/tsa_boss_1_3.wav");
  mix->addTrack("res/music/title.wav");
}

BackgroundManager::~BackgroundManager()
{
  delete mix;
}

void BackgroundManager::update()
{
  if (GameStates::getFirstTick())
  {
    removeObjects();
    mix->stop();
    switch (GameStates::getState())
    {
      case GameState::INTRO:
      {
        mix->play(0);
        break;
      }
      case GameState::HOME:
      {
        mix->play(1);
        Background* b = new Background(renderer, "res/images/home.jpg", {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, 0);
        objects.push_back(b);
        break;
      }
      case GameState::MENU:
      {
        Background* b;
        b = new Background(renderer, "res/images/menu/level_select.png", {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, 0);
        objects.push_back(b);
        break;
      }
      case GameState::LEVEL:
      {
        Background* b;
        switch (Game::levelInfo.level)
        {
          case 4:
            break;
          case 3:
            break;
          case 2:
            break;
          case 1:
            break;
          default:
          case 0:
            b = new Background(renderer, "res/images/levels/grassy.jpg", {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, 0);
            objects.push_back(b);
            break;
        }
      }
    }
  }
}
