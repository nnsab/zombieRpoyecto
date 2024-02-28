#include "include/Zombie.h"

Zombie::Zombie() 
  : m_health(2)
{
  m_shape.Set_texture("./Resources/Sprites/ZOMBIE_NORMAL.png");
  m_shape.shape.setOrigin(m_shape.texture.getSize().x / 2.f, m_shape.texture.getSize().y / 2.f);
  m_speed = 2;
  m_shape.shape.setPosition(-400.f, 400.f);
}

float Zombie::Get_health()
{
  return m_health;
}

void Zombie::Set_health(float health)
{
  m_health = health;
}
