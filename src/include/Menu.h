#include <SFML/Graphics.hpp>

#define NUMBER_ITEMS 2

class Menu
{
public:
  Menu(sf::RenderWindow& window);

  void Processes(sf::RenderWindow& window, int& game_state);

private:
  void Selector();
  void Render(sf::RenderWindow& window); // Render se encarga de dibujar las cosas

private:
  int m_index;

  sf::Font m_font;
  sf::Text m_text[NUMBER_ITEMS];
  sf::Text m_outline;
};
