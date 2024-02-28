#include "include/Sprite_base.h"

Sprite_base::Sprite_base(){}

Sprite_base::Sprite_base(std::string texture_path) 
{
  if(!texture.loadFromFile(texture_path))
  {
  }

  shape.setTexture(texture);
}

void Sprite_base::Set_texture(std::string texture_path)
{
  if(!texture.loadFromFile(texture_path))
  {
  }

  shape.setTexture(texture);
}
