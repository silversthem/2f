#ifndef TILESET_HPP
#define TILESET_HPP

#include "Texture.hpp"

namespace f2 {

class Tileset : public Texture {
protected:
  sf::Vector2u offset;
  sf::Vector2u boxOffset;
  sf::Vector2u box;
  sf::Vector2u frames;
public:
  /* Constructors */
  Tileset();
  Tileset(sf::Texture *t, sf::Vector2u const& b, sf::Vector2u const& fr);
  /* Setters */
  void setOffset(int const& xoffset, int const& yoffset);
  /* Getters */
  /* Methods */
  void tile(int const& n); // Gets nth tile
  void tile(int const& x, int const& y); // Gets tile at position (x*box.x + offset.x, y*box.y + offset.y)
};

};

#endif
