#include "Entity.h"

class Zombie : public Entity
{
public:
  Zombie();

  float Get_health();

  void Set_health(float health);

public:
  int attack_timer;

private:
  float m_health;

};
