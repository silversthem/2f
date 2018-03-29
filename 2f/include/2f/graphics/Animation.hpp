/*
  An animation is an chain of textures being displayed one after the other
  Transformations on existing textures are also possible
  This is an abstract class
*/

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <utility>
#include <SFML/Graphics/Texture.hpp>

namespace f2 {

class Animation {
public:
  virtual std::pair<sf::Texture*,sf::IntRect> update(int const& nticks) = 0;
};

};

#endif
