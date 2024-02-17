#include "Player.h"

class Play_mode
{
public:
  Play_mode();

  void Processes(sf::RenderWindow& window);

private:
  void Quit(sf::RenderWindow& window);
  void Render(sf::RenderWindow& window); // Render se encarga de dibujar las cosas

private:
  Player m_player;
};
