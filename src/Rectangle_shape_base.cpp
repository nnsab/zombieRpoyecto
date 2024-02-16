#include "include/Rectangle_shape_base.h"

Rectangle_shape_base::Rectangle_shape_base(sf::Vector2f size, sf::Color color) 
: m_size(size)
, m_color(color)
, shape(m_size)
{
  shape.setSize(m_size);
  shape.setFillColor(m_color);
}
