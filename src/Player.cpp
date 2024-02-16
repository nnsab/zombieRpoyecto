#include <math.h>
#include "include/Player.h"

Player::Player() 
  : m_shape(sf::Vector2f(12.f, 12.f), sf::Color::White)
  , m_player_speed(4.f)
{
  m_shape.shape.setOrigin(m_shape.m_size / 2.f);
}

void Player::Draw_player(sf::RenderWindow& window)
{
  window.draw(m_shape.shape);
}

sf::Vector2f Player::Get_shape_center()
{
  return sf::Vector2f(m_shape.shape.getPosition().x, m_shape.shape.getPosition().y);
}

sf::Vector2f Player::Get_aim_direction(sf::Vector2f mouse_position_window)
{
  return mouse_position_window - Get_shape_center();
}

sf::Vector2f Player::Get_normalized_aim_direction(sf::Vector2f mouse_position_window)
{
  float vector_length = sqrt(pow(Get_aim_direction(mouse_position_window).x, 2) + pow(Get_aim_direction(mouse_position_window).y, 2));
  sf::Vector2f normalized_aim_direction = Get_aim_direction(mouse_position_window) / vector_length;
  

  return normalized_aim_direction;
}

float Player::Get_aim_angle(sf::Vector2f mouse_position_window)
{
  float angle = atanf(Get_aim_direction(mouse_position_window).y / Get_aim_direction(mouse_position_window).x) * (180 / M_PIl);
  //std::cout << Get_aim_direction(mouse_position_window).x << " " << Get_aim_direction(mouse_position_window).y << " " << angle << "\n";

  return angle;
}

void Player::Set_shape_rotation(sf::Vector2f mouse_position_window)
{
  m_shape.shape.setRotation(Get_aim_angle(mouse_position_window));
}

void Player::Player_movement()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    m_shape.shape.move(-m_player_speed, 0.f);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    m_shape.shape.move(m_player_speed, 0.f);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    m_shape.shape.move(0.f, -m_player_speed);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    m_shape.shape.move(0.f, m_player_speed);
}

void Player::Draw_bullets(sf::RenderWindow& window)
{
  for (int i = 0; i < m_bullets.size(); i++)
  {
    window.draw(m_bullets[i].Get_shape());
  }
}

void Player::Shooting(sf::Vector2f mouse_position_window)
{
  if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    m_bullet.Set_shape_position(Get_shape_center());
    m_bullet.Set_shape_rotation(Get_aim_angle(mouse_position_window));
    m_bullet.Set_current_velocity(Get_normalized_aim_direction(mouse_position_window));

    m_bullets.push_back(Bullet(m_bullet));
  }

  for(int i = 0; i < m_bullets.size(); i++)
    m_bullets[i].Move_shape(m_bullets[i].Get_current_velocity());
}

void Player::Bullet_border_collision(sf::RenderWindow& window)
{
  for(int i = 0; i < m_bullets.size(); i++)
  {
    if(m_bullets[i].Get_shape().getPosition().x < 0 || m_bullets[i].Get_shape().getPosition().x > window.getSize().x || 
      m_bullets[i].Get_shape().getPosition().y < 0 || m_bullets[i].Get_shape().getPosition().y > window.getSize().y)
    {
      m_bullets.erase(m_bullets.begin() + i);
    }
  }
}
