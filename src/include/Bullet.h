#include <SFML/Graphics.hpp>

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
  sf::RectangleShape m_shape;
  sf::Vector2f m_shape_size;
  sf::Color m_shape_color;

  sf::Vector2f m_current_velocity;
  float m_max_speed;
};
