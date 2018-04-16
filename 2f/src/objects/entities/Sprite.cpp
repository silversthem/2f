#include "2f/objects/entities/Sprite.hpp"
#include <iostream>
using namespace f2;

Sprite::Sprite() {

}

bool Sprite::inBounds(sf::IntRect const& r) {

}

void Sprite::relativePosition(sf::Vector2i const& center, int const& angle) {
    sf::Vector2i p = pos(center);
    setPosition(p.x,p.y);
    if(angle != 0) {
      /* Computing new position relative to orientation */
      
      setRotation(angle);
    }
}

void Sprite::centerOrigin() {
  setOrigin(getTextureRect().width/2,getTextureRect().height/2);
}

void Sprite::render(sf::RenderTarget *t) {
  t->draw(*this);
}
