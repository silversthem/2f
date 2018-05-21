#include "2f/graphics/Tileset.hpp"

using namespace f2;

Tileset::Tileset() {
  offset = sf::Vector2u(0,0);
  boxOffset = sf::Vector2u(0,0);
  setTextureRect(sf::IntRect(0,0,0,0));
}

Tileset::Tileset(sf::Texture *t, sf::Vector2u const& b, sf::Vector2u const& fr) {
  Tileset();
  setTexture(*t);
  box.x = b.x;
  box.y = b.y;
  frames.x = fr.x;
  frames.y = fr.y;
  setTextureRect(sf::IntRect(0,0,b.x,b.y));
}

void Tileset::setOffset(int const& xoffset, int const& yoffset) {
  offset.x = xoffset;
  offset.y = yoffset;
}

void Tileset::tile(int const& n) {
  int m = n % (frames.x * frames.y);
  tile(m % frames.x, m / frames.x);
}

void Tileset::tile(int const& x, int const& y) {
  setTextureRect(sf::IntRect(x*box.x + offset.x,y*box.y + offset.y,box.x,box.y));
}
