#include "include/Menu.h"

Menu::Menu(sf::RenderWindow& window) : m_index(0)
{
  //if(!m_font.loadFromFile(""))
  {

  }

  //m_text[0].setFont(m_font);
  m_text[0].setFillColor(sf::Color::White);
  m_text[0].setString("Jugar");
  m_text[0].setPosition(window.getSize().x / 2.f, window.getSize().y / 3.f);

  //m_text[1].setFont(m_font);
  m_text[1].setFillColor(sf::Color::White);
  m_text[1].setString("Salir");
  m_text[1].setPosition(window.getSize().x / 2.f, window.getSize().y / 3.f * 2.f);

}

void Menu::Processes(sf::RenderWindow& window, int& game_state)
{
  Selector();

  Render(window);
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
  {
    if(m_index == 1)
    {
      window.close();
    }
    else 
      game_state = 1;
  }
}

void Menu::Selector()
{
  m_outline = m_text[m_index];
  m_outline.setFillColor(sf::Color::Red);
  m_outline.move(sf::Vector2f(m_outline.getPosition().x, m_outline.getPosition().y + 4));

  if(m_index == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    m_index++;

  else if(m_index == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    m_index--;

}

void Menu::Render(sf::RenderWindow& window)
{
  window.clear(sf::Color(39, 20, 43, 255));

  window.draw(m_outline);
  for(int i = 0; i < NUMBER_ITEMS; i++)
    window.draw(m_text[i]);

  window.display();
}
