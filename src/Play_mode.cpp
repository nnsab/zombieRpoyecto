#include "include/Play_mode.h"
#include <SFML/Graphics/RenderWindow.hpp>

Play_mode::Play_mode()
{
}

void Play_mode::Processes(sf::RenderWindow& window)
{
  Quit(window);

  m_player.Player_movement();
  m_player.Set_shape_rotation(sf::Vector2f(sf::Mouse::getPosition(window)));
  m_player.Shooting(sf::Vector2f(sf::Mouse::getPosition(window)));

  m_player.Bullet_border_collision(window);

  Render(window);
}

void Play_mode::Quit(sf::RenderWindow& window)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    window.close();
}

void Play_mode::Render(sf::RenderWindow& window)
{
  window.clear(sf::Color(50, 40, 54, 255));

  m_player.Draw_bullets(window);
  m_player.Draw_player(window);

  window.display();
}
