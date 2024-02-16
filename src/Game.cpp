#include "include/Game.h"
//#include <iostream>

Game::Game() : m_window(sf::VideoMode(1366, 768), "Game", 
                        sf::Style::Fullscreen)
                        //sf::Style::Default)
{
  m_window.setFramerateLimit(60);
  m_window.setKeyRepeatEnabled(true);
}

// Función de bucle de juego (proceso de fotogramas)
void Game::run()
{
  while (m_window.isOpen())
  {
    processEvents();

    m_player.Player_movement();
    m_player.Set_shape_rotation(sf::Vector2f(sf::Mouse::getPosition(m_window)));
    m_player.Shooting(sf::Vector2f(sf::Mouse::getPosition(m_window)));
    m_player.Bullet_border_collision(m_window);

    // Debug
    // Posición del jugador
    //std::cout << m_player.Get_shape_center().x << " " << m_player.Get_shape_center().y << "\n";
    // Dirección normalizada de vista del jugador
    //std::cout << m_player.Get_normalized_aim_direction(sf::Vector2f(sf::Mouse::getPosition(m_window))).x << " " << m_player.Get_normalized_aim_direction(sf::Vector2f(sf::Mouse::getPosition(m_window))).y << "\n";

    render();
  }
}

// Aquí se procesan todos los eventos (Teclado, joystick, etc.)
void Game::processEvents()
{
  sf::Event event;
  while (m_window.pollEvent(event))
  {
    switch (event.type)
    {

      case sf::Event::Closed:
        m_window.close();
        break;

    }
  }
}

// render se encarga de dibujar las cosas
void Game::render()
{
  m_window.clear(sf::Color(50, 40, 54, 255));

  // Objetos a dibujar
  m_player.Draw_bullets(m_window);
  m_player.Draw_player(m_window);

  m_window.display();
}
