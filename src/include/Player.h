#include "Entity.h"
#include "Bullet.h"
#include "Weapon.h"

#define MAX_BULLETS 100

class Player : public Entity
{
public:
  Player(sf::RenderWindow& window);

  void Shooting(sf::Vector2f mouse_position_window);

  void Draw_bullets(sf::RenderWindow& window);

public:
  Bullet bullets[MAX_BULLETS];
  Weapon weapon;

private:
  int m_bullet_number;
  int m_firerate_timer;

};
