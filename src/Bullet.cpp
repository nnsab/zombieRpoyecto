#include "include/Bullet.h"

Bullet::Bullet() 
  : m_shape(sf::Vector2f(2.f, 80.f), sf::Color(252, 185, 60, 192))
  , m_current_velocity(0.f, 0.f)
  , m_max_speed(80.f)
{
  m_shape.shape.setOrigin(m_shape.m_size.x / 2, m_shape.m_size.y / 2);
}

sf::RectangleShape Bullet::Get_shape()
{
  return m_shape.shape;
}

sf::Vector2f Bullet::Get_current_velocity()
{
  return m_current_velocity;
}

void Bullet::Set_shape_position(sf::Vector2f position)
{
  m_shape.shape.setPosition(position);
}

void Bullet::Set_current_velocity(sf::Vector2f aim_direction)
{
  m_current_velocity = aim_direction * m_max_speed;
}

void Bullet::Move_shape(sf::Vector2f vector)
{
  m_shape.shape.move(vector);
}

void Bullet::Set_shape_rotation(float angle)
{
  m_shape.shape.setRotation(angle + 90.f);
}
