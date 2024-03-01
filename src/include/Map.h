#include <SFML/Graphics.hpp>
#include "Sprite_base.h"

#define NUMBER_WALLS 48
#define NUMBER_WINDOWS 44

class Wall
{
public:
  Wall();

public:
  //Sprite_base sprite;
  sf::RectangleShape shape;
  sf::Color color = sf::Color(127, 255, 0, 255);
};

class Window
{
public:
  Window();

public:
  //Sprite_base sprite;
  sf::RectangleShape shape;
  sf::Color color = sf::Color(130, 181, 181, 255);
};

class Map
{
public:
  Map(sf::RenderWindow& game_window);

  void Draw_map(sf::RenderWindow& game_window);
  Wall wall[NUMBER_WALLS];
  Window window[NUMBER_WINDOWS];

private:
  sf::Vector2f m_map_size;

  //Sprite_base m_background;
  sf::RectangleShape m_background;

};

