#include "2f/gui/Background.hpp"

using namespace f2;

Background::Background() {

}

Background::Background(sf::Texture &text) {
  texture = text;
  sprite.setTexture(texture);
}

void Background::loadFromFile(std::string const& file) {
  texture.loadFromFile(file);
  texture.setRepeated(true);
  sprite.setTexture(texture);
}

void Background::render(sf::RenderTarget *t, sf::IntRect const& size, sf::Vector2i const& center, bool const& couldRotate) {
  // @TODO : Include couldRotate instead of default behavior
  sprite.setTextureRect(sf::IntRect(center.x,center.y,size.width*2,size.height*2));
  sprite.setScale(1,1);
  sprite.setPosition(-(size.width/2),-(size.height/2));
  t->draw(sprite);
}
