#include "include/Weapon.h"

Weapon::Weapon()
{
}

Weapon::Weapon(float damage, int firerate_delay)
{
  m_damage = damage;
  m_firerate_delay = firerate_delay;
}

float Weapon::Get_damage()
{
  return m_damage;
}

int Weapon::Get_firerate_delay()
{
  return m_firerate_delay;
}
