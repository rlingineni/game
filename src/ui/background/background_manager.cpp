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
  mix->addTrack("res/music/mysterious_shores.wav");
  mix->addTrack("res/music/run.wav");
  mix->addTrack("res/music/death.wav");
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
        mix->play(2);
        Background* b;
        b = new Background(renderer, "res/images/menu/level_select.png", {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, 0);
        objects.push_back(b);
        break;
      }
      case GameState::LEVEL:
      {
        mix->play(3);
        Background* b;
        switch (Game::levelInfo.level)
        {
          case 4:
            objects.push_back(new Background(renderer, "res/images/levels/grass.png", {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, 0));
            break;
          case 3:
            objects.push_back(new Background(renderer, "res/images/levels/space.png", {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, 0));
            break;
          case 2:
            objects.push_back(new Background(renderer, "res/images/levels/ice.png", {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, 0));
            break;
          case 1:
            objects.push_back(new Background(renderer, "res/images/levels/water.png", {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, 0));
            break;
          default:
          case 0:
            objects.push_back(new Background(renderer, "res/images/levels/grass.png", {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, 0));
            break;
        }
        break;
      }
      case GameState::OVER:
      {
        mix->play(4);
      }
    }
  }
}
