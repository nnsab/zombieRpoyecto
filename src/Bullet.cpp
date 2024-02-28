#include "include/Bullet.h"

Bullet::Bullet() 
  : m_shape_size(2, 20)
  , m_shape_color(sf::Color(252, 185, 60, 192))
  , m_current_velocity(0.f, 0.f)
{
  m_shape.setSize(m_shape_size);
  m_shape.setOrigin(m_shape_size.x / 2, m_shape_size.y / 2);
  m_shape.setFillColor(m_shape_color);
  m_shape.setPosition(-100.f, -100.f);
  m_speed = 25;
}

sf::RectangleShape Bullet::Get_shape()
{
  return m_shape;
}

sf::Vector2f Bullet::Get_current_velocity()
{
  return m_current_velocity;
}

void Bullet::Set_current_velocity(sf::Vector2f aim_direction)
{
  m_current_velocity = aim_direction * m_speed;
}

void Bullet::Move_shape(sf::Vector2f vector)
{
  m_shape.move(vector);
}

void Bullet::Set_shape_position(sf::Vector2f position)
{
  m_shape.setPosition(position);
}

void Bullet::Set_shape_rotation(float angle)
{
  m_shape.setRotation(angle + 90.f);
}

