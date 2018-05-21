/*

*/

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "../../graphics/Texture.hpp"
#include "../Entity.hpp"

namespace f2 {

class Sprite : public Entity, public Texture {
protected:

public:
  Sprite(); // Creates a sprite
  bool inBounds(sf::IntRect const& bounds); // rect collision by default
  void render(sf::RenderTarget *t); // Renders sprite
};

};

#endif
