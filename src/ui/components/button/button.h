#ifndef BUTTON
#define BUTTON

#include "ui_component.h"
#include "renderer.h"
#include <SDL2/SDL.h>

enum class ButtonState {ANIMATE, NEUTRAL, SELECTED};

class Button : public UIComponent
{
public:
  // Constructor
  Button(Renderer*, SDL_Rect startPos, SDL_Rect endPos, void (*clickHandler)(Button*), bool);
  void update();

  void click();
  bool selected;
private:
  ButtonState state;
  // Events
  void (*onClick)(Button*);
  SDL_Rect myPos;
  unsigned int ticks;
};

#endif
