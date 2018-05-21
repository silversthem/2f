#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace f2 {

/* Current texture states, as an array of int */
struct TextureStates {
  int* states;
  int  size;
  TextureStates();
  TextureStates(int const& s);
  TextureStates(int const& s, int* sts);
};

class Texture : public sf::Sprite {
public:
  /* Methods */
  void centerOrigin();
  /* Virtual Methods */
  virtual void update(int const& nt, TextureStates const& tstates);
  virtual void blit(sf::RenderTarget *rt,sf::Vector2i const& pos);
};

};

#endif
