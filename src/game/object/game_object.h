#ifndef GAME_OBJECT
#define GAME_OBJECT

class GameObject
{
public:
  virtual ~GameObject() {}

  virtual void update() = 0;
  virtual void draw() = 0;
};

#endif
