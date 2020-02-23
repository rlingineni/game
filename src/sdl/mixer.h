#ifndef MIXER
#define MIXER

#include "SDL_mixer.h" 
#include <vector>

class Mixer
{
public:
  Mixer();
  ~Mixer();
  void play(int);
  void pause();
  void stop();
  void addTrack(const char* fpath);
private:
  std::vector<Mix_Music*> music;
};


#endif
