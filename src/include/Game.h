#include "Menu.h"
#include "Play_mode.h"

class Game 
{

public:
  Game();
  void Run();

private:
  void Process_events();

public:
  int m_game_state;
  
private:
  sf::RenderWindow m_window; // ventana del juego

  Menu m_menu;
  Play_mode m_game;
};
