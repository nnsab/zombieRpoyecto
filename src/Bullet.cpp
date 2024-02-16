#include "include/Bullet.h"

Bullet::Bullet() : 
  m_shape_size(2.f, 80.f),
  m_shape_color(sf::Color(252, 203, 78, 192)),
  m_current_velocity(0.f, 0.f),
  m_max_speed(80.f)
{
  m_shape.setSize(m_shape_size);
  m_shape.setFillColor(m_shape_color);
  m_shape.setOrigin(m_shape_size.x / 2, m_shape_size.y);
}

sf::RectangleShape Bullet::Get_shape()
{
  return m_shape;
}

sf::Vector2f Bullet::Get_current_velocity()
{
  return m_current_velocity;
}

float Bullet::Get_rotation()
{
  return m_shape.getRotation();
}

void Bullet::Set_shape_position(sf::Vector2f position)
{
  m_shape.setPosition(position);
}

void Bullet::Set_current_velocity(sf::Vector2f aim_direction)
{
  m_current_velocity = aim_direction * m_max_speed;
}

void Bullet::Move_shape(sf::Vector2f vector)
{
  m_shape.move(vector);
}

void Bullet::Set_shape_rotation(float angle)
{
  m_shape.setRotation(angle + 90.f);
}
