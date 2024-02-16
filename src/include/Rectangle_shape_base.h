#include <SFML/Graphics.hpp>

class Rectangle_shape_base
{
public:
  Rectangle_shape_base(sf::Vector2f size, sf::Color color);

public:
  sf::RectangleShape shape;
  sf::Vector2f m_size;
  sf::Color m_color;
};
