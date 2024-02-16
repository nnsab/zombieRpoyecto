#include "Player.h"

class Game 
{
public:
  Game();
  void run();

private:
  void processEvents();
  void render();

private:
  sf::RenderWindow m_window; // ventana del juego
  Player m_player;
};
