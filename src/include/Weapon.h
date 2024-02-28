#include <SFML/Graphics.hpp>

class Weapon
{
public:
  Weapon();
  Weapon(float damage, int firerate_delay);

  float Get_damage();
  int Get_firerate_delay();

private:
  sf::Sprite m_sprite;
  sf::Texture m_texture;

  float m_damage;
  int m_firerate_delay;
};
