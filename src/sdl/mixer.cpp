#include "mixer.h"

Mixer::Mixer()
{

}

Mixer::~Mixer()
{
  for (auto track : music)
    Mix_FreeMusic(track);
}

void Mixer::play(int i)
{
  Mix_PlayMusic(music[i], -1);
}

void Mixer::pause()
{
  Mix_PauseMusic();
}

void Mixer::stop()
{
  Mix_HaltMusic();
}

void Mixer::addTrack(const char* fpath)
{
  music.push_back(Mix_LoadMUS(fpath));
}
