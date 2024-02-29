#include "Map.h"
#include "Player.h"
#include "Zombie.h"

#define SPAWN_LOCATION_NUMBER 5
#define MAX_ZOMBIES 200

class Play_mode
{
public:
  Play_mode(sf::RenderWindow& window);

  void Processes(sf::RenderWindow& window);

private:

  void Player_movement();
  void Check_wall_collision();
  void Difficulty();
  void Spawn_zombies();
  void Bullet_collisions();

  void Render(sf::RenderWindow& window);

private:
  Map m_map;

  Player m_player;

  Zombie m_zombie;
  Zombie m_zombies[MAX_ZOMBIES];
  unsigned short int m_zombie_iteration;

  short int m_spawned_zombies;

  unsigned short int m_wave;
  unsigned short int m_wave_zombies;
  unsigned short int m_spawn_counter;
  unsigned short int m_spawn_timer;

  int m_points;
  int m_killed_zombies_statistic;

  const sf::Vector2f m_spawn_location[SPAWN_LOCATION_NUMBER]
  {
    sf::Vector2f(180.f, 20.f),
    sf::Vector2f(410.f, 20.f),
    sf::Vector2f(510.f, 20.f),
    sf::Vector2f(900.f, 20.f),
    sf::Vector2f(1100.f, 20.f)
  };

  sf::Font m_font;
  sf::Text m_display_points;
  sf::Text m_display_wave;
};
