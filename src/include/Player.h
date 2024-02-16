#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"

class Player
{
public:
  Player();

  void Draw_player(sf::RenderWindow& window);
  sf::Vector2f Get_shape_center();
  sf::Vector2f Get_aim_direction(sf::Vector2f mouse_position_window);
  sf::Vector2f Get_normalized_aim_direction(sf::Vector2f mouse_position_window);
  float Get_aim_angle(sf::Vector2f mouse_position_window);

  void Set_shape_rotation(sf::Vector2f mouse_position_window);
  void Player_movement();

  void Draw_bullets(sf::RenderWindow& window);
  void Shooting(sf::Vector2f mouse_position_window);
  void Bullet_border_collision(sf::RenderWindow& window);

private:
  sf::RectangleShape m_shape;
  const sf::Vector2f m_shape_size;
  const sf::Color m_shape_color;

  float m_player_speed;

  Bullet m_bullet;
  std::vector<Bullet> m_bullets;
};
