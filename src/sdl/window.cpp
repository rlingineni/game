#include "window.h"

Window::Window(const char* title, int x, int y, int width, int height, bool fullScreen)
{
  int flags = 0;

  if (fullScreen)
    flags = SDL_WINDOW_FULLSCREEN;

  window = SDL_CreateWindow(title, x, y, width, height, flags);
  //SDL_SetWindowResizable(window, SDL_TRUE);
}

Window::~Window()
{
  // SDL_DestroyWindow(window); Valgrind reporting this causes memory leaks
}

SDL_Window* Window::getWindow()
{
  return window;
}
