#ifndef GAME
#define GAME

#include "window.h"
#include "renderer.h"
#include "texture.h"
#include "manager_manager.h"
#include "game_input.h"

class Game
{
public:
  static void init(const char* title, int x, int y, int width, int height, bool fullScreen);
  static void close();

  static void input();
  static void update();
  static void draw();

  static bool isRunning();
  static Texture* getTexture();
  static GameInput inputs;
private:
  Game();
  ~Game();

  static bool running;
  static Window* window;
  static Renderer* renderer;
  static Texture* texture;
  static ManagerManager* manager;
};

#endif
