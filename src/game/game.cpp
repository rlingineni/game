#include "game.h"
#include "game_states.h"

bool Game::running = true;
Window* Game::window;
Renderer* Game::renderer;
Texture* Game::texture;
ManagerManager* Game::manager;

void Game::init(const char* title, int x, int y, int width, int height, bool fullScreen)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    window = new Window(title, x, y, width, height, fullScreen);
    renderer = new Renderer(window->getWindow());
    texture = new Texture("", renderer);
    manager = new ManagerManager(renderer);
    running = true;
  }
  else
  {
    running = false;
  }
}

void Game::close()
{
  delete window;
  delete renderer;
  delete texture;
  delete manager;

  SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
  SDL_Quit();
}

void Game::input()
{
  SDL_Event e;
  SDL_PollEvent(&e);
  switch (e.type)
  {
    case SDL_QUIT:
      running = false;
      break;
  }
}

void Game::update()
{
  manager->update();
  GameStates::updateState();
}

void Game::draw()
{
  renderer->setDrawColor(0x00, 0x99, 0xdb, 255);
  renderer->clear();

  manager->draw();

  renderer->present();
}

bool Game::isRunning()
{
  return running;
}

Texture* Game::getTexture()
{
  return texture;
}
