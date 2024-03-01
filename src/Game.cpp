//#include <iostream>

#include "include/Game.h"

Game::Game() 
  : m_window(sf::VideoMode(1366, 768), "Game", 
             sf::Style::Fullscreen)
             // Para mirar la consola y el juego al mismo tiempo
             //sf::Style::Default)
  , m_menu(m_window)
  , m_game(m_window)
{
  // Fotogramas por segundo máximos 60
  m_window.setFramerateLimit(60);

  // Se inicializa game_state en 0 (Menú)
  game_state = 0;
}

// Función de bucle de juego (proceso de fotogramas)
void Game::Run()
{
  while (m_window.isOpen())
  {
    Process_events();

    switch (game_state)
    {
      case 0:
        m_menu.Processes(m_window, game_state);
        break;

      case 1:
        m_game.Processes(m_window);
        break;
    }
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
