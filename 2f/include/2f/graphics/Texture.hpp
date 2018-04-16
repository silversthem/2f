#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace f2 {

class Texture : public sf::Sprite {
public:
  /* Methods */
  /* Virtual Methods */
  virtual void update(int const& nt) {}
  virtual void blit(sf::RenderTarget *rt,sf::Vector2i const& pos) {
    setPosition(pos.x,pos.y);
    rt->draw(*this);
  }
};

};

#endif
