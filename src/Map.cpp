#include "include/Map.h"

#define WINDOW_SIZE 30
#define WINDOW_THICKNESS 4

Wall::Wall()
{
  shape.setFillColor(color);
}

Window::Window()
{
  shape.setFillColor(color);
}

Map::Map(sf::RenderWindow& game_window) 
  : m_background(sf::Vector2f(1024.f, 576.f))
{

  // Piso
  m_background.setPosition((sf::Vector2f(game_window.getSize()) - m_background.getSize()) / 2.f);
  m_background.setFillColor(sf::Color(58, 58, 46, 255));

  // Pared externa izquierda
  wall[0].shape.setSize(sf::Vector2f(6, m_background.getSize().y));
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
  wall[16].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - 6, m_background.getPosition().y));

  window[14].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[14].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - WINDOW_THICKNESS, wall[16].shape.getPosition().y + wall[16].shape.getSize().y));

  wall[17].shape.setSize(sf::Vector2f(6, 10));
  wall[17].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - 6, window[14].shape.getPosition().y + WINDOW_SIZE));

  window[15].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[15].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - WINDOW_THICKNESS, wall[17].shape.getPosition().y + wall[17].shape.getSize().y));

  wall[18].shape.setSize(sf::Vector2f(6, 20));
  wall[18].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - 6, window[15].shape.getPosition().y + WINDOW_SIZE));

  window[16].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[16].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - WINDOW_THICKNESS, wall[18].shape.getPosition().y + wall[18].shape.getSize().y));

  wall[19].shape.setSize(sf::Vector2f(6, 10));
  wall[19].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - 6, window[16].shape.getPosition().y + WINDOW_SIZE));

  window[17].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[17].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - WINDOW_THICKNESS, wall[19].shape.getPosition().y + wall[19].shape.getSize().y));

  wall[20].shape.setSize(sf::Vector2f(6, 10));
  wall[20].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - 6, window[17].shape.getPosition().y + WINDOW_SIZE));

  window[18].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[18].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - WINDOW_THICKNESS, wall[20].shape.getPosition().y + wall[20].shape.getSize().y));

  wall[21].shape.setSize(sf::Vector2f(6, 40));
  wall[21].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - 6, window[18].shape.getPosition().y + WINDOW_SIZE));

  window[19].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[19].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - WINDOW_THICKNESS, wall[21].shape.getPosition().y + wall[21].shape.getSize().y));

  wall[22].shape.setSize(sf::Vector2f(6, 10));
  wall[22].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - 6, window[19].shape.getPosition().y + WINDOW_SIZE));

  window[20].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[20].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - WINDOW_THICKNESS, wall[22].shape.getPosition().y + wall[22].shape.getSize().y));

  wall[23].shape.setSize(sf::Vector2f(6, 10));
  wall[23].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - 6, window[20].shape.getPosition().y + WINDOW_SIZE));

  window[21].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[21].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - WINDOW_THICKNESS, wall[23].shape.getPosition().y + wall[23].shape.getSize().y));

  wall[24].shape.setSize(sf::Vector2f(6, 10));
  wall[24].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - 6, window[21].shape.getPosition().y + WINDOW_SIZE));

  window[22].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[22].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - WINDOW_THICKNESS, wall[24].shape.getPosition().y + wall[24].shape.getSize().y));

  wall[25].shape.setSize(sf::Vector2f(6, 10));
  wall[25].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - 6, window[22].shape.getPosition().y + WINDOW_SIZE));

  window[23].shape.setSize(sf::Vector2f(WINDOW_THICKNESS, WINDOW_SIZE));
  window[23].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - WINDOW_THICKNESS, wall[25].shape.getPosition().y + wall[25].shape.getSize().y));

  wall[26].shape.setSize(sf::Vector2f(6, 76));
  wall[26].shape.setPosition(sf::Vector2f(m_background.getPosition().x + m_background.getSize().x - 6, window[23].shape.getPosition().y + WINDOW_SIZE));

  // Pared externa inferior 
  wall[27].shape.setSize(sf::Vector2f(35, 6));
  wall[27].shape.setPosition(sf::Vector2f(m_background.getPosition().x, m_background.getPosition().y + m_background.getSize().y - 6));

  window[24].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[24].shape.setPosition(sf::Vector2f(wall[27].shape.getPosition().x + wall[27].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[28].shape.setSize(sf::Vector2f(10, 6));
  wall[28].shape.setPosition(sf::Vector2f(window[24].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[25].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[25].shape.setPosition(sf::Vector2f(wall[28].shape.getPosition().x + wall[28].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[29].shape.setSize(sf::Vector2f(10, 6));
  wall[29].shape.setPosition(sf::Vector2f(window[25].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[26].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[26].shape.setPosition(sf::Vector2f(wall[29].shape.getPosition().x + wall[29].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[30].shape.setSize(sf::Vector2f(35, 6));
  wall[30].shape.setPosition(sf::Vector2f(window[26].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[27].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[27].shape.setPosition(sf::Vector2f(wall[30].shape.getPosition().x + wall[30].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[31].shape.setSize(sf::Vector2f(10, 6));
  wall[31].shape.setPosition(sf::Vector2f(window[27].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[28].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[28].shape.setPosition(sf::Vector2f(wall[31].shape.getPosition().x + wall[31].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[32].shape.setSize(sf::Vector2f(10, 6));
  wall[32].shape.setPosition(sf::Vector2f(window[28].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[29].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[29].shape.setPosition(sf::Vector2f(wall[32].shape.getPosition().x + wall[32].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[33].shape.setSize(sf::Vector2f(35, 6));
  wall[33].shape.setPosition(sf::Vector2f(window[29].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[30].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[30].shape.setPosition(sf::Vector2f(wall[33].shape.getPosition().x + wall[33].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[34].shape.setSize(sf::Vector2f(10, 6));
  wall[34].shape.setPosition(sf::Vector2f(window[30].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[31].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[31].shape.setPosition(sf::Vector2f(wall[34].shape.getPosition().x + wall[34].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[35].shape.setSize(sf::Vector2f(10, 6));
  wall[35].shape.setPosition(sf::Vector2f(window[31].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[32].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[32].shape.setPosition(sf::Vector2f(wall[35].shape.getPosition().x + wall[35].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[36].shape.setSize(sf::Vector2f(50, 6));
  wall[36].shape.setPosition(sf::Vector2f(window[32].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[33].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[33].shape.setPosition(sf::Vector2f(wall[36].shape.getPosition().x + wall[36].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[37].shape.setSize(sf::Vector2f(10, 6));
  wall[37].shape.setPosition(sf::Vector2f(window[33].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[34].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[34].shape.setPosition(sf::Vector2f(wall[37].shape.getPosition().x + wall[37].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[38].shape.setSize(sf::Vector2f(10, 6));
  wall[38].shape.setPosition(sf::Vector2f(window[34].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[35].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[35].shape.setPosition(sf::Vector2f(wall[38].shape.getPosition().x + wall[38].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[39].shape.setSize(sf::Vector2f(35, 6));
  wall[39].shape.setPosition(sf::Vector2f(window[35].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[36].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[36].shape.setPosition(sf::Vector2f(wall[39].shape.getPosition().x + wall[39].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[40].shape.setSize(sf::Vector2f(35, 6));
  wall[40].shape.setPosition(sf::Vector2f(window[36].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[37].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[37].shape.setPosition(sf::Vector2f(wall[40].shape.getPosition().x + wall[40].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[41].shape.setSize(sf::Vector2f(10, 6));
  wall[41].shape.setPosition(sf::Vector2f(window[37].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[38].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[38].shape.setPosition(sf::Vector2f(wall[41].shape.getPosition().x + wall[41].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[42].shape.setSize(sf::Vector2f(10, 6));
  wall[42].shape.setPosition(sf::Vector2f(window[38].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[39].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[39].shape.setPosition(sf::Vector2f(wall[42].shape.getPosition().x + wall[42].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[43].shape.setSize(sf::Vector2f(74, 6));
  wall[43].shape.setPosition(sf::Vector2f(window[39].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[40].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[40].shape.setPosition(sf::Vector2f(wall[43].shape.getPosition().x + wall[43].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[44].shape.setSize(sf::Vector2f(10, 6));
  wall[44].shape.setPosition(sf::Vector2f(window[40].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[41].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[41].shape.setPosition(sf::Vector2f(wall[44].shape.getPosition().x + wall[44].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[45].shape.setSize(sf::Vector2f(10, 6));
  wall[45].shape.setPosition(sf::Vector2f(window[41].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

  window[42].shape.setSize(sf::Vector2f(WINDOW_SIZE, WINDOW_THICKNESS));
  window[42].shape.setPosition(sf::Vector2f(wall[45].shape.getPosition().x + wall[45].shape.getSize().x, m_background.getPosition().y + m_background.getSize().y - 6 + 2));

  wall[46].shape.setSize(sf::Vector2f(35, 6));
  wall[46].shape.setPosition(sf::Vector2f(window[42].shape.getPosition().x + WINDOW_SIZE, m_background.getPosition().y + m_background.getSize().y - 6));

}

void Map::Draw_map(sf::RenderWindow& game_window)
{
  game_window.draw(m_background);

  for(int i = 0; i < NUMBER_WALLS; i++)
    game_window.draw(wall[i].shape);

  for(size_t i = 0; i < NUMBER_WINDOWS; i++)
    game_window.draw(window[i].shape);
}
