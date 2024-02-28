#include <math.h>
#include "include/Entity.h"

void Entity::Draw_shape(sf::RenderWindow& window)
{
  window.draw(m_shape.shape);
}

sf::Sprite Entity::Get_shape()
{
  return m_shape.shape;
}

sf::Vector2f Entity::Get_shape_center()
{
  return sf::Vector2f(m_shape.shape.getPosition().x, m_shape.shape.getPosition().y);
}

sf::Vector2f Entity::Get_aim_direction(sf::Vector2f target_position)
{
  return target_position - Get_shape_center();
}

sf::Vector2f Entity::Get_normalized_aim_direction(sf::Vector2f target_position)
{
  float vector_length = sqrt(pow(Get_aim_direction(target_position).x, 2) + pow(Get_aim_direction(target_position).y, 2));
  sf::Vector2f normalized_aim_direction = Get_aim_direction(target_position) / vector_length;
  

  return normalized_aim_direction;
}

float Entity::Get_aim_angle(sf::Vector2f target_position)
{
  // Trigonometría aplicada a las coordenadas del mouse respecto a la posición del jugador para conseguir el ángulo y conversión de radianes a grados
  float angle = atanf(Get_aim_direction(target_position).y / Get_aim_direction(target_position).x) * (180 / M_PIl);

  //std::cout << Get_aim_direction(target_position).x << " " << Get_aim_direction(target_position).y << " " << angle << "\n";

  // Para que el sprite rote los 360 grados en vez de 180 cuando las coordenadas del mouse respecto a la posición del jugador tienen x negativo
  if(Get_aim_direction(target_position).x < 0)
    angle += 180;

  return angle;
}

float Entity::Get_speed()
{
  return m_speed;
}

void Entity::Set_shape_position(sf::Vector2f position)
{
  m_shape.shape.setPosition(position);
}

void Entity::Set_shape_rotation(float angle)
{
  m_shape.shape.setRotation(angle);
}

void Entity::Move_shape(sf::Vector2f direction)
{
  m_shape.shape.move(direction);
}
