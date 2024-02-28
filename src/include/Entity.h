#include <SFML/Graphics.hpp>
#include "Sprite_base.h"

#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
  void Draw_shape(sf::RenderWindow& window);

  sf::Sprite& Get_shape();
  sf::Vector2f Get_shape_center();
  sf::Vector2f Get_aim_direction(sf::Vector2f target_position);
  sf::Vector2f Get_normalized_aim_direction(sf::Vector2f target_position);
  float Get_aim_angle(sf::Vector2f target_position);

  void Set_shape_position(sf::Vector2f position);
  void Set_shape_rotation(float angle);

protected:
  Sprite_base m_shape;

  float m_speed;
};

#endif // !ENTITY_H
