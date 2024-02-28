//#include <iostream>

#include "include/Player.h"

Player::Player(sf::RenderWindow& window) : weapon(2, 20)
{
  m_shape.Set_texture("./Resources/Sprites/jugador_player_segun_vos.png");
  m_shape.shape.setOrigin(m_shape.texture.getSize().x / 2.f, m_shape.texture.getSize().y / 2.f);
  m_firerate_timer = weapon.Get_firerate_delay();
  m_speed = 2.5;
  m_shape.shape.setPosition(sf::Vector2f(window.getSize()) / 2.f);

}

void Player::Shooting(sf::Vector2f mouse_position_window)
{
  //std::cout << m_firerate_timer << "\n";
  if(m_firerate_timer >= weapon.Get_firerate_delay())
  {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      if(m_bullet_number < MAX_BULLETS)
      {
        m_bullet_number++;
      }

      else
      {
        m_bullet_number = 0;
      }

      bullets[m_bullet_number].Set_shape_position(Get_shape_center());
      bullets[m_bullet_number].Set_shape_rotation(Get_aim_angle(mouse_position_window));
      bullets[m_bullet_number].Set_current_velocity(Get_normalized_aim_direction(mouse_position_window));

      m_firerate_timer = 0;
    }
  }

  else
  {
    m_firerate_timer++;
  }

  for(int i = 0; i < MAX_BULLETS; i++)
    bullets[i].Move_shape(bullets[i].Get_current_velocity());
}

void Player::Draw_bullets(sf::RenderWindow& window)
{
  for (int i = 0; i < MAX_BULLETS; i++)
  {
    window.draw(bullets[i].Get_shape());
  }
}
