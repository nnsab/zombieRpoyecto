#include <SFML/Graphics.hpp>

#ifndef SPRITE_BASE_H
#define SPRITE_BASE_H

class Sprite_base
{
public:
  Sprite_base();
  Sprite_base(std::string texture_path);

  void Set_texture(std::string texture_path);

public:
  sf::Sprite shape;
  sf::Texture texture;
};

#endif // !SPRITE_BASE_H
