#include <time.h>
#include <iostream>
#include "include/Play_mode.h"

#define SPAWN_DELAY 60

Play_mode::Play_mode(sf::RenderWindow& window)
  : m_map(window)
  , m_player(window)
  , m_zombie_iteration(0)
  , m_spawned_zombies(0)
  , m_wave(1)
  , m_wave_zombies(20)
  , m_spawn_counter(0)
  , m_spawn_timer(60)
  , m_points(0)
  , m_killed_zombies_statistic(0)
{
  srand(time(NULL));

  if(!m_font.loadFromFile("./Resources/Fonts/CloisterBlackLight-axjg.ttf"))
  {
  }

  m_display_wave.setFont(m_font);
  m_display_wave.setCharacterSize(30);
  m_display_wave.setFillColor(sf::Color::Red);
  m_display_wave.setPosition(10, 0);

  m_display_points.setFont(m_font);
  m_display_points.setCharacterSize(30);
  m_display_points.setFillColor(sf::Color::Red);
  m_display_points.setPosition(1170.f, 720);
}

void Play_mode::Processes(sf::RenderWindow& window)
{
  //std::cout << m_spawned_zombies << " " << m_spawn_counter << " " << m_wave_zombies << "\n";
  Player_movement();
  Check_wall_collision();
  m_player.Set_shape_rotation(m_player.Get_aim_angle(sf::Vector2f(sf::Mouse::getPosition())));
  m_player.Shooting(sf::Vector2f(sf::Mouse::getPosition()));
  Spawn_zombies();
  //for(size_t i = 0; i < MAX_ZOMBIES; i++)
  //  m_zombies[i].Set_shape_rotation(m_zombies[i].Get_aim_angle(m_player.Get_shape_center()));
  Difficulty();
  Bullet_collisions();

  m_display_wave.setString("Ronda: " + std::to_string(m_wave));
  m_display_points.setString("Puntos: " + std::to_string(m_points));

  Render(window);
}

void Play_mode::Player_movement()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    m_player.Move_shape(sf::Vector2f(-m_player.Get_speed(), 0.f));

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    m_player.Move_shape(sf::Vector2f(m_player.Get_speed(), 0.f));

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    m_player.Move_shape(sf::Vector2f(0.f, -m_player.Get_speed()));

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    m_player.Move_shape(sf::Vector2f(0.f, m_player.Get_speed()));
}

void Play_mode::Check_wall_collision()
{
  for (size_t i = 0; i < NUMBER_WALLS; i++)
  {
    if(m_player.Get_shape().getGlobalBounds().intersects(m_map.wall[i].shape.getGlobalBounds()))
    {
      std::cout << "Collision" << "\n";
      if(m_map.wall[i].shape.getSize().x > m_map.wall[i].shape.getSize().y)
      {
        m_player.Move_shape(-(sf::Vector2f(0.f, m_map.wall[i].shape.getPosition().y - m_player.Get_shape_center().y)));
      }
      
      else
      {
        m_player.Move_shape(-(sf::Vector2f(m_map.wall[i].shape.getPosition().x - m_player.Get_shape_center().x, 0.f)));
      }
      break;
    }
  }
}

void Play_mode::Difficulty()
{
  if(m_spawned_zombies <= 0 && m_spawn_counter == m_wave_zombies)
  {
    m_zombie.Set_health(m_zombie.Get_health() * 1.1);
    m_wave_zombies = m_wave_zombies * 1.1;
    m_wave++;

    m_spawn_counter = 0;
  }
}

void Play_mode::Spawn_zombies()
{
  if(m_spawn_timer >= SPAWN_DELAY && m_spawn_counter < m_wave_zombies)
  {
    if(m_zombie_iteration >= MAX_ZOMBIES)
      m_zombie_iteration = 0;

    m_zombies[m_zombie_iteration] = m_zombie;
    m_zombies[m_zombie_iteration].Set_shape_position(m_spawn_location[rand() % SPAWN_LOCATION_NUMBER]);

    m_zombie_iteration++;

    m_spawn_counter++;
    m_spawned_zombies++;

    m_spawn_timer = 0;
  }

  m_spawn_timer++;
}

void Play_mode::Bullet_collisions()
{
  for(size_t i = 0; i < MAX_BULLETS; i++)
  {
    for(size_t j = 0; j < MAX_ZOMBIES; j++)
    {
      if(m_player.bullets[i].Get_shape().getGlobalBounds().intersects(m_zombies[j].Get_shape().getGlobalBounds()))
      {
        m_player.bullets[i].Set_shape_position(sf::Vector2f(-100, -100));
        m_player.bullets[i].Set_current_velocity(sf::Vector2f(0.f, 0.f));

        m_zombies[j].Set_health(m_zombies[j].Get_health() - m_player.weapon.Get_damage());

        if(m_zombies[j].Get_health() < 0)
        {
          m_zombies[j].Set_shape_position(sf::Vector2f(-400, 400));

          m_spawned_zombies--;

          if(m_spawned_zombies < 0)
            m_spawned_zombies = 0;

          m_points += 50;
          m_killed_zombies_statistic++;
        }
        break;
      }
    }

    for(size_t k = 0; k < NUMBER_WALLS; k++)
    {
      if(m_player.bullets[i].Get_shape().getGlobalBounds().intersects(m_map.wall[k].shape.getGlobalBounds()))
      {
        m_player.bullets[i].Set_shape_position(sf::Vector2f(-100, -100));
        m_player.bullets[i].Set_current_velocity(sf::Vector2f(0.f, 0.f));
        break;
      }
    }
  }
}

void Play_mode::Render(sf::RenderWindow& window)
{
  window.clear();

  m_map.Draw_map(window);
  m_player.Draw_bullets(window);
  
  for(size_t i = 0; i < MAX_ZOMBIES; i++)
    m_zombies[i].Draw_shape(window);

  m_player.Draw_shape(window);

  window.draw(m_display_wave);
  window.draw(m_display_points);

  window.display();
}
