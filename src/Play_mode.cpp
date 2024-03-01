#include <time.h>
#include "include/Play_mode.h"

#define SPAWN_DELAY 65
#define ZOMBIE_ATTACK_DELAY 20

Play_mode::Play_mode(sf::RenderWindow& window)
  : m_map(window)
  , m_player(window)
  , m_zombie_iteration(0)
  , m_spawned_zombies(0)
  , m_wave(1)
  , m_wave_zombies(20) // Se inicializa en 20 para que sea la cantidad de zombies generada en la primera ronda
  , m_spawn_counter(0)
  , m_spawn_timer(60) // Se inicializa en 60 para generar un zombie apenas empiece el juego
  , m_points(0)
  , m_killed_zombies_statistic(0)
{
  srand(time(NULL));

  // Carga de fuente para el texto de la interfaz de usuario
  if(!m_font.loadFromFile("./Resources/Fonts/CloisterBlackLight-axjg.ttf"))
  {
  }

  // Parámetros de los textos
  m_display_wave.setFont(m_font);
  m_display_wave.setCharacterSize(30);
  m_display_wave.setFillColor(sf::Color::Red);
  m_display_wave.setPosition(10, 0);

  m_display_points.setFont(m_font);
  m_display_points.setCharacterSize(30);
  m_display_points.setFillColor(sf::Color::Red);
  m_display_points.setPosition(1170.f, 720);

  m_death_screen.setFont(m_font);
  m_death_screen.setCharacterSize(80);
  m_death_screen.setFillColor(sf::Color::Red);
  m_death_screen.setPosition(460, 200);
  m_death_screen.setString("MORISTE");

  m_display_killed_zombies.setFont(m_font);
  m_display_killed_zombies.setCharacterSize(40);
  m_display_killed_zombies.setFillColor(sf::Color::Red);
  m_display_killed_zombies.setPosition(500, 400);

  m_display_quit.setFont(m_font);
  m_display_quit.setCharacterSize(20);
  m_display_quit.setFillColor(sf::Color::Red);
  m_display_quit.setPosition(550, 600);
  m_display_quit.setString("Presiona escape para salir");
}

void Play_mode::Processes(sf::RenderWindow& window)
{
  // Si el jugador está dentro de la pantalla (o sea vivo)
  if(m_player.Get_shape_center().x > 0.f)
  {
    Player_movement();
    Check_obstacle_collision();
    m_player.Set_shape_rotation(m_player.Get_aim_angle(sf::Vector2f(sf::Mouse::getPosition())));
    m_player.Shooting(sf::Vector2f(sf::Mouse::getPosition()));
    Spawn_zombies();
    Difficulty();
    Zombies_behavior(window);
    Zombie_attack();
    Bullet_collisions();

    // Actualización de interfaz de usuario
    // Número de ronda
    m_display_wave.setString("Ronda: " + std::to_string(m_wave));
    // Puntos del jugador
    m_display_points.setString("Puntos: " + std::to_string(m_points));
    // Número de zombies asesinados (para mostrar en pantalla de muerte)
    m_display_killed_zombies.setString("Mataste a " + std::to_string(m_killed_zombies_statistic) + " zombies");

    Render(window);
  }

  else
  {
    Render(window);

    window.draw(m_death_screen);
    window.draw(m_display_killed_zombies);
    window.draw(m_display_quit);

    window.display();

    Quit(window);
  }
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

void Play_mode::Check_obstacle_collision()
{
  // Verifica cada pared
  for(size_t i = 0; i < NUMBER_WALLS; i++)
  {
    // Si el rectángulo del jugador intercepta el rectángulo de m_map.wall[i]
    if(m_player.Get_shape().getGlobalBounds().intersects(m_map.wall[i].shape.getGlobalBounds()))
    {
      // Verifica en qué coordenada es más grande la pared para saber su dirección
      if(m_map.wall[i].shape.getSize().x > m_map.wall[i].shape.getSize().y)
      {
        // Mueve al jugador a la distancia de la dimensión menor de la pared
        m_player.Move_shape(-(sf::Vector2f(0.f, m_map.wall[i].shape.getPosition().y - m_player.Get_shape_center().y)));
      }
      
      else
      {
        // Mueve al jugador a la distancia de la dimensión menor de la pared
        m_player.Move_shape(-(sf::Vector2f(m_map.wall[i].shape.getPosition().x - m_player.Get_shape_center().x, 0.f)));
      }

      return;
    }
  }

  // Verifica cada ventana
  for(size_t i = 0; i < NUMBER_WINDOWS; i++)
  {
    // Si el rectángulo del jugador intercepta el rectángulo de m_map.window[i]
    if(m_player.Get_shape().getGlobalBounds().intersects(m_map.window[i].shape.getGlobalBounds()))
    {
      // Verifica en qué coordenada es más grande la ventana para saber su dirección
      if(m_map.window[i].shape.getSize().x > m_map.window[i].shape.getSize().y)
      {
        // Mueve al jugador a la distancia de la dimensión menor de la ventana
        m_player.Move_shape(-(sf::Vector2f(0.f, m_map.window[i].shape.getPosition().y - m_player.Get_shape_center().y)));
      }

      else
      {
        // Mueve al jugador a la distancia de la dimensión menor de la ventana
        m_player.Move_shape(-(sf::Vector2f(m_map.window[i].shape.getPosition().x - m_player.Get_shape_center().x, 0.f)));
      }

      return;
    }
  }
}

void Play_mode::Spawn_zombies()
{
  // El temporizador aumenta su valor cada fotograma
  // Si su valor es mayor o igual al de SPAWN_DELAY(60) y no se llegó al máximo de zombies de la ronda, se generará un zombie
  if(m_spawn_timer >= SPAWN_DELAY && m_spawn_counter < m_wave_zombies)
  {
    if(m_zombie_iteration >= MAX_ZOMBIES)
      m_zombie_iteration = 0;

    // Se iguala m_zombies[m_zombie_iteration] a m_zombie ya que tiene los atributos actualizados de cada ronda
    m_zombies[m_zombie_iteration] = m_zombie;
    // Se lo posiciona en uno de los lugares de aparición aleatoriamente
    m_zombies[m_zombie_iteration].Set_shape_position(m_spawn_location[rand() % SPAWN_LOCATION_NUMBER]);

    // Aumenta el iterador del vector de zombies
    m_zombie_iteration++;

    // Aumenta el contador de zombies generados por ronda
    m_spawn_counter++;
    // Aumenta el contador de zombies en pantalla
    m_spawned_zombies++;

    // Se reinicia el temporizador
    m_spawn_timer = 0;
  }

  // Aumenta el temporizador
  m_spawn_timer++;
}

void Play_mode::Difficulty()
{
  // Si todos los zombies en pantalla mueren y todos los zombies de la ronda ya se generaron
  if(m_spawned_zombies <= 0 && m_spawn_counter == m_wave_zombies)
  {
    // Se aumenta la vida de los zombies un 10%
    m_zombie.Set_health(m_zombie.Get_health() * 1.1);
    // Se aumenta la cantidad de zombies por ronda un 10%
    m_wave_zombies = m_wave_zombies * 1.1;
    // Aumenta el número de ronda
    m_wave++;

    // Se reinicia el contador de zombies generados por ronda
    m_spawn_counter = 0;
  }
}

void Play_mode::Zombies_behavior(sf::RenderWindow& window)
{
  for(size_t i = 0; i < MAX_ZOMBIES; i++)
  {
    // Solo funciona si los zombies están dentro de la pantalla
    if(m_zombies[i].Get_shape().getPosition().x > 0.f)
    {
      // Rota a el zombie para que mire hacia el jugador
      m_zombies[i].Set_shape_rotation(m_zombies[i].Get_aim_angle(m_player.Get_shape_center()));
      // Mueve a los zombies hacia el jugador a la velocidad de la dirección vectorial a la que está el jugador multiplicada por la rapidez del zombie
      m_zombies[i].Move_shape(m_zombies[i].Get_normalized_aim_direction(m_player.Get_shape_center()) * m_zombies[i].Get_speed());
    }
  }
}

void Play_mode::Zombie_attack()
{
  // Itera sobre todos los zombies para chequearlos
  for(size_t i = 0; i < MAX_ZOMBIES; i++)
  {
    // Si m_zombies[i] collisiona con m_player
    if(m_zombies[i].Get_shape().getGlobalBounds().intersects(m_player.Get_shape().getGlobalBounds()))
    {
      // Si el temporizador es llega al mínimo para atacar
      if(m_zombies[i].attack_timer >= ZOMBIE_ATTACK_DELAY)
      {
        // Restarle vida al jugador
        m_player.Set_shape_position(sf::Vector2f(-200.f, 0.f));
      }

      else
      {
        // Incrementa el temporizador
        m_zombies[i].attack_timer++;
      }
    }
  }
}

void Play_mode::Bullet_collisions()
{
  for(size_t i = 0; i < MAX_BULLETS; i++)
  {
    for(size_t j = 0; j < MAX_ZOMBIES; j++)
    {
      // Si el rectángulo de bullets[i] intercepta el rectángulo de m_zombies[j]
      if(m_player.bullets[i].Get_shape().getGlobalBounds().intersects(m_zombies[j].Get_shape().getGlobalBounds()))
      {
        // Se pone el rectángulo de la bala fuera de la pantalla
        m_player.bullets[i].Set_shape_position(sf::Vector2f(-100, -100));
        // Se pone la velocidad en 0 para que no se siga moviendo
        m_player.bullets[i].Set_current_velocity(sf::Vector2f(0.f, 0.f));

        // Se reduce m_zombies[j].m_health según el valor de m_player.weapon.damage
        m_zombies[j].Set_health(m_zombies[j].Get_health() - m_player.weapon.Get_damage());

        // Si m_zombies[j].m_health está por debajo de 0 se lo considera muerto
        if(m_zombies[j].Get_health() < 0)
        {
          // Se lo mueve fuera de la pantalla
          m_zombies[j].Set_shape_position(sf::Vector2f(-400, 400));

          // Se reduce el contador de zombies en pantalla
          m_spawned_zombies--;

          if(m_spawned_zombies < 0)
            m_spawned_zombies = 0;
          
          // Se agregan los puntos y la cantidad de zombies eliminados a la estadística
          m_points += 50;
          m_killed_zombies_statistic++;
        }
      }
    }

    for(size_t j = 0; j < NUMBER_WALLS; j++)
    {
      // Si el rectángulo de bullets[i] intercepta el rectángulo de m_map.wall[j]
      if(m_player.bullets[i].Get_shape().getGlobalBounds().intersects(m_map.wall[j].shape.getGlobalBounds()))
      {
        // Se pone el rectángulo de la bala fuera de la pantalla
        m_player.bullets[i].Set_shape_position(sf::Vector2f(-100, -100));
        // Se pone la velocidad en 0 para que no se siga moviendo
        m_player.bullets[i].Set_current_velocity(sf::Vector2f(0.f, 0.f));
        break;
      }
    }
  }
}

void Play_mode::Render(sf::RenderWindow& window)
{
  // Limpia la pantalla
  window.clear(sf::Color(40, 40, 39, 255));

  // Dibuja
  m_map.Draw_map(window);
  m_player.Draw_bullets(window);
  
  for(size_t i = 0; i < MAX_ZOMBIES; i++)
    m_zombies[i].Draw_shape(window);

  m_player.Draw_shape(window);

  // Interfaz de usuario
  window.draw(m_display_wave);
  window.draw(m_display_points);

  // Actualiza la pantalla
  window.display();
}

void Play_mode::Quit(sf::RenderWindow& window)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
  {
    window.close();
  }
}
