#ifndef TEXTURE
#define TEXTURE

#include "renderer.h"
#include <SDL2/SDL.h>

class Texture
{
public:
  Texture(const char*, Renderer*);
  ~Texture();
  SDL_Texture* getTexture();
private:
  SDL_Texture* texture;
};

#endif
