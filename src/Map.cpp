#include "include/Map.h"

#define WINDOW_SIZE 30
#define WINDOW_THICKNESS 3

Wall::Wall()
{
  shape.setFillColor(color);
}

Window::Window()
{
  shape.setFillColor(color);
}

Map::Map(sf::RenderWindow& game_window) 
  : m_map_size(1024.f, 576.f)
  , m_background(m_map_size)
{

  // Piso
  m_background.setPosition((sf::Vector2f(game_window.getSize()) - m_map_size) / 2.f);
  m_background.setFillColor(sf::Color::Black);

  // Pared externa izquierda
  wall[0].shape.setSize(sf::Vector2f(6, m_map_size.y));
  wall[0].shape.setPosition(sf::Vector2f(m_background.getPosition()));

  // Pared externa superior
  wall[1].shape.setSize(sf::Vector2f(100, 6));
  wall[1].shape.setPosition(sf::Vector2f(m_background.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[0].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[0].shape.setPosition(sf::Vector2f(wall[1].shape.getPosition().x + wall[1].shape.getSize().x, m_background.getPosition().y));

  wall[2].shape.setSize(sf::Vector2f(10, 6));
  wall[2].shape.setPosition(sf::Vector2f(window[0].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[1].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[1].shape.setPosition(sf::Vector2f(wall[2].shape.getPosition().x + wall[2].shape.getSize().x, m_background.getPosition().y));

  wall[3].shape.setSize(sf::Vector2f(30, 6));
  wall[3].shape.setPosition(sf::Vector2f(window[1].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[2].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[2].shape.setPosition(sf::Vector2f(wall[3].shape.getPosition().x + wall[3].shape.getSize().x, m_background.getPosition().y));

  wall[4].shape.setSize(sf::Vector2f(20, 6));
  wall[4].shape.setPosition(sf::Vector2f(window[2].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[3].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[3].shape.setPosition(sf::Vector2f(wall[4].shape.getPosition().x + wall[4].shape.getSize().x, m_background.getPosition().y));

  wall[5].shape.setSize(sf::Vector2f(10, 6));
  wall[5].shape.setPosition(sf::Vector2f(window[3].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[4].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[4].shape.setPosition(sf::Vector2f(wall[5].shape.getPosition().x + wall[5].shape.getSize().x, m_background.getPosition().y));

  wall[6].shape.setSize(sf::Vector2f(40, 6));
  wall[6].shape.setPosition(sf::Vector2f(window[4].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[5].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[5].shape.setPosition(sf::Vector2f(wall[6].shape.getPosition().x + wall[6].shape.getSize().x, m_background.getPosition().y));

  wall[7].shape.setSize(sf::Vector2f(10, 6));
  wall[7].shape.setPosition(sf::Vector2f(window[5].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[6].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[6].shape.setPosition(sf::Vector2f(wall[7].shape.getPosition().x + wall[7].shape.getSize().x, m_background.getPosition().y));

  wall[8].shape.setSize(sf::Vector2f(200, 6));
  wall[8].shape.setPosition(sf::Vector2f(window[6].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[7].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[7].shape.setPosition(sf::Vector2f(wall[8].shape.getPosition().x + wall[8].shape.getSize().x, m_background.getPosition().y));

  wall[9].shape.setSize(sf::Vector2f(10, 6));
  wall[9].shape.setPosition(sf::Vector2f(window[7].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[8].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[8].shape.setPosition(sf::Vector2f(wall[9].shape.getPosition().x + wall[9].shape.getSize().x, m_background.getPosition().y));

  wall[10].shape.setSize(sf::Vector2f(10, 6));
  wall[10].shape.setPosition(sf::Vector2f(window[8].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[9].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[9].shape.setPosition(sf::Vector2f(wall[10].shape.getPosition().x + wall[10].shape.getSize().x, m_background.getPosition().y));

  wall[11].shape.setSize(sf::Vector2f(10, 6));
  wall[11].shape.setPosition(sf::Vector2f(window[9].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[10].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[10].shape.setPosition(sf::Vector2f(wall[11].shape.getPosition().x + wall[11].shape.getSize().x, m_background.getPosition().y));

  wall[12].shape.setSize(sf::Vector2f(10, 6));
  wall[12].shape.setPosition(sf::Vector2f(window[10].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[11].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[11].shape.setPosition(sf::Vector2f(wall[12].shape.getPosition().x + wall[12].shape.getSize().x, m_background.getPosition().y));

  wall[13].shape.setSize(sf::Vector2f(10, 6));
  wall[13].shape.setPosition(sf::Vector2f(window[11].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[12].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[12].shape.setPosition(sf::Vector2f(wall[13].shape.getPosition().x + wall[13].shape.getSize().x, m_background.getPosition().y));

  wall[14].shape.setSize(sf::Vector2f(10, 6));
  wall[14].shape.setPosition(sf::Vector2f(window[12].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  window[13].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[13].shape.setPosition(sf::Vector2f(wall[14].shape.getPosition().x + wall[14].shape.getSize().x, m_background.getPosition().y));

  wall[15].shape.setSize(sf::Vector2f(94, 6));
  wall[15].shape.setPosition(sf::Vector2f(window[13].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y));

  // Pared externa derecha
  wall[16].shape.setSize(sf::Vector2f(6, 70));
  wall[16].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - 6, m_background.getPosition().y));

  window[14].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[14].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - WINDOW_THICKNESS, wall[16].shape.getPosition().y + wall[16].shape.getSize().y));

  wall[17].shape.setSize(sf::Vector2f(6, 10));
  wall[17].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - 6, window[14].shape.getPosition().y + WINDOW_SIZE));

  window[15].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[15].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - WINDOW_THICKNESS, wall[17].shape.getPosition().y + wall[17].shape.getSize().y));

  wall[18].shape.setSize(sf::Vector2f(6, 20));
  wall[18].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - 6, window[15].shape.getPosition().y + WINDOW_SIZE));

  window[16].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[16].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - WINDOW_THICKNESS, wall[18].shape.getPosition().y + wall[18].shape.getSize().y));

  wall[19].shape.setSize(sf::Vector2f(6, 10));
  wall[19].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - 6, window[16].shape.getPosition().y + WINDOW_SIZE));

  window[17].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[17].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - WINDOW_THICKNESS, wall[19].shape.getPosition().y + wall[19].shape.getSize().y));

  wall[20].shape.setSize(sf::Vector2f(6, 10));
  wall[20].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - 6, window[17].shape.getPosition().y + WINDOW_SIZE));

  window[18].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[18].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - WINDOW_THICKNESS, wall[20].shape.getPosition().y + wall[20].shape.getSize().y));

  wall[21].shape.setSize(sf::Vector2f(6, 40));
  wall[21].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - 6, window[18].shape.getPosition().y + WINDOW_SIZE));

  window[19].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[19].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - WINDOW_THICKNESS, wall[21].shape.getPosition().y + wall[21].shape.getSize().y));

  wall[22].shape.setSize(sf::Vector2f(6, 10));
  wall[22].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - 6, window[19].shape.getPosition().y + WINDOW_SIZE));

  window[20].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[20].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - WINDOW_THICKNESS, wall[22].shape.getPosition().y + wall[22].shape.getSize().y));

  wall[23].shape.setSize(sf::Vector2f(6, 10));
  wall[23].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - 6, window[20].shape.getPosition().y + WINDOW_SIZE));

  window[21].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[21].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - WINDOW_THICKNESS, wall[23].shape.getPosition().y + wall[23].shape.getSize().y));

  wall[24].shape.setSize(sf::Vector2f(6, 10));
  wall[24].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - 6, window[21].shape.getPosition().y + WINDOW_SIZE));

  window[22].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[22].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - WINDOW_THICKNESS, wall[24].shape.getPosition().y + wall[24].shape.getSize().y));

  wall[25].shape.setSize(sf::Vector2f(6, 10));
  wall[25].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - 6, window[22].shape.getPosition().y + WINDOW_SIZE));

  window[23].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[23].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - WINDOW_THICKNESS, wall[25].shape.getPosition().y + wall[25].shape.getSize().y));

  wall[26].shape.setSize(sf::Vector2f(6, 76));
  wall[26].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_map_size.x - 6, window[23].shape.getPosition().y + WINDOW_SIZE));

  /*
  // Pared externa inferior 
  m_wall[30].setSize(sf::Vector2f(20, 6));
  m_wall[30].setPosition(sf::Vector2f(m_wall[0].getPosition().x, m_wall[0].getPosition().y + 570));
  m_wall[30].setFillColor(sf::Color::Yellow);
  
  m_wall[31].setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  m_wall[31].setPosition(sf::Vector2f(m_wall[30].getPosition().x + m_wall[30].getSize().x, m_wall[0].getPosition().y + 570 + 3));
  m_wall[31].setFillColor(sf::Color::Cyan);

  m_wall[32].setSize(sf::Vector2f(10, 6));
  m_wall[32].setPosition(sf::Vector2f(m_wall[31].getPosition().x + m_wall[31].getSize().x, m_wall[0].getPosition().y + 570));
  m_wall[32].setFillColor(sf::Color::Yellow);
  
  m_wall[33].setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  m_wall[33].setPosition(sf::Vector2f(m_wall[32].getPosition().x + m_wall[32].getSize().x, m_wall[0].getPosition().y + 570 + 3));
  m_wall[33].setFillColor(sf::Color::Cyan);

  m_wall[34].setSize(sf::Vector2f(20, 6));
  m_wall[34].setPosition(sf::Vector2f(m_wall[33].getPosition().x + m_wall[33].getSize().x, m_wall[0].getPosition().y + 570));
  m_wall[34].setFillColor(sf::Color::Yellow);
  
  m_wall[35].setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  m_wall[35].setPosition(sf::Vector2f(m_wall[34].getPosition().x + m_wall[34].getSize().x, m_wall[0].getPosition().y + 570 + 3));
  m_wall[35].setFillColor(sf::Color::Cyan);

  m_wall[36].setSize(sf::Vector2f(10, 6));
  m_wall[36].setPosition(sf::Vector2f(m_wall[35].getPosition().x + m_wall[35].getSize().x, m_wall[0].getPosition().y + 570));
  m_wall[36].setFillColor(sf::Color::Yellow);
  
  m_wall[37].setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  m_wall[37].setPosition(sf::Vector2f(m_wall[36].getPosition().x + m_wall[36].getSize().x, m_wall[0].getPosition().y + 570 + 3));
  m_wall[37].setFillColor(sf::Color::Cyan);

  m_wall[38].setSize(sf::Vector2f(20, 6));
  m_wall[38].setPosition(sf::Vector2f(m_wall[37].getPosition().x + m_wall[37].getSize().x, m_wall[0].getPosition().y + 570));
  m_wall[38].setFillColor(sf::Color::Yellow);
  
  */
}

void Map::Draw_map(sf::RenderWindow& game_window)
{
  game_window.draw(m_background);

  for(int i = 0; i < NUMBER_WALLS; i++)
    game_window.draw(wall[i].shape);

  for(size_t i = 0; i < NUMBER_WINDOWS; i++)
    game_window.draw(window[i].shape);
}
