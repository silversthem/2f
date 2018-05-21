#include "2f/graphics/Texture.hpp"

using namespace f2;


TextureStates::TextureStates() {
  size = 0;
}

TextureStates::TextureStates(int const& s) {
  size = s;
}

TextureStates::TextureStates(int const& s, int* sts) {
  size = s;
  states = sts;
}

void Texture::centerOrigin() {
  setOrigin(getTextureRect().width/2,getTextureRect().height/2);
}

void Texture::update(int const& nt, TextureStates const& tstates) {

}

void Texture::blit(sf::RenderTarget *rt,sf::Vector2i const& pos) {
  setPosition(pos.x,pos.y);
  rt->draw(*this);
}
