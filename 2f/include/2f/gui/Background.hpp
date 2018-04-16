/*

*/

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace f2 {

class Background {
protected:
  sf::Texture texture;
  sf::Sprite sprite;
public:
  Background();
  Background(sf::Texture &text);
  void loadFromFile(std::string const& file);
  void render(sf::RenderTarget *t, sf::IntRect const& size, sf::Vector2i const& center);
};

};

#endif
