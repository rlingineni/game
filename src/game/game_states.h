#ifndef GAME_STATES
#define GAME_STATES

enum class GameState {INTRO, HOME, MENU, LEVEL, OVER, QUIT, WIN};

class GameStates
{
public:
  static GameState getState(); // Return current state
  static bool getFirstTick();

  static void changeState(GameState); // Queue state for change
  // Below are only for game class to use
  static void updateState(); // Change state before update (for game class only)
private:
  GameStates(); // Prevent initialization
  static GameState state;
  static GameState newState;
  static bool firstTick; // First tick of a state
};

#endif
