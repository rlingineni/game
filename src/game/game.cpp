#include "game.h"
#include "game_states.h"

GameInput Game::inputs = {false, false, false, false, false, false};
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
    texture = new Texture("res/spritesheet.png", renderer);
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
    case SDL_KEYDOWN:
      switch (e.key.keysym.sym)
      {
        case SDLK_LEFT:
          inputs.left = true;
          break;
        case SDLK_RIGHT:
          inputs.right = true;
          break;
        case SDLK_UP:
          inputs.up = true;
          break;
        case SDLK_DOWN:
          inputs.down = true;
          break;
        case SDLK_o:
          inputs.attack = true;
          break;
        case SDLK_p:
          inputs.special = true;
          break;
      }
      break;
    case SDL_KEYUP:
      switch (e.key.keysym.sym)
      {
        case SDLK_LEFT:
          inputs.left = false;
          break;
        case SDLK_RIGHT:
          inputs.right = false;
          break;
        case SDLK_UP:
          inputs.up = false;
          break;
        case SDLK_DOWN:
          inputs.down = false;
          break;
        case SDLK_o:
          inputs.attack = false;
          break;
        case SDLK_p:
          inputs.special = false;
          break;
      }
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
  renderer->setDrawColor(0, 0, 0, 255);
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
