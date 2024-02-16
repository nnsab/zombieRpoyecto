#include "Rectangle_shape_base.h"

class Bullet
{
public:
  Bullet();

  sf::RectangleShape Get_shape();
  sf::Vector2f Get_current_velocity();
  float Get_rotation();

  void Set_shape_position(sf::Vector2f position);
  void Set_current_velocity(sf::Vector2f aim_direction);
  void Move_shape(sf::Vector2f vector);
  void Set_shape_rotation(float angle);

private:
  Rectangle_shape_base m_shape;

  sf::Vector2f m_current_velocity;
  float m_max_speed;
};
