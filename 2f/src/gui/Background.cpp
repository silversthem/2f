#include "2f/gui/Background.hpp"

using namespace f2;

Background::Background() {

}

Background::Background(sf::Texture &text) {
  texture = text;
}

void Background::loadFromFile(std::string const& file) {
  texture.loadFromFile(file);
  texture.setRepeated(true);
}

void Background::render(sf::RenderTarget *t, sf::IntRect const& size, sf::Vector2i const& center) {
  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(center.x,center.y,size.width,size.height));
  t->draw(sprite);
}
