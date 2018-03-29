/*

*/

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include "../Entity.hpp"

namespace f2 {

class Sprite : public Entity, public sf::Sprite {
protected:

public:
  Sprite(); // Creates a sprite
  bool inBounds(sf::IntRect const& bounds); // rect collision by default
  void relativePosition(sf::Vector2i const& center);
  void centerOrigin(); // Sets rendering origin to middle of texture
  void render(sf::RenderTarget *t); // Renders sprite
};

};

#endif
