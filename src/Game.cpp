#include "include/Game.h"
//#include <iostream>

Game::Game() 
  : m_window(sf::VideoMode(1366, 768), "Game", 
                        //sf::Style::Fullscreen)
                        // Para mirar la consola y el juego al mismo tiempo
                        sf::Style::Default)
  , m_menu(m_window)
  , m_game()
{
  m_window.setFramerateLimit(60);

  m_game_state = 0;
}

// Función de bucle de juego (proceso de fotogramas)
void Game::Run()
{
  while (m_window.isOpen())
  {
    Process_events();

    switch (m_game_state)
    {
      case 0:
        m_menu.Processes(m_window, m_game_state);
        break;

      case 1:
        m_game.Processes(m_window);
        break;
    }
    // Debug
    // Posición del jugador
    //std::cout << m_player.Get_shape_center().x << " " << m_player.Get_shape_center().y << "\n";
    // Dirección normalizada de vista del jugador
    //std::cout << m_player.Get_normalized_aim_direction(sf::Vector2f(sf::Mouse::getPosition(m_window))).x << " " << m_player.Get_normalized_aim_direction(sf::Vector2f(sf::Mouse::getPosition(m_window))).y << "\n";
  }
}

// Aquí se procesan todos los eventos (Teclado, joystick, etc.)
void Game::Process_events()
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
