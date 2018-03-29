#include "2f/objects/entities/Sprite.hpp"

using namespace f2;

Sprite::Sprite() {

}

bool Sprite::inBounds(sf::IntRect const& r) {

}

void Sprite::relativePosition(sf::Vector2i const& center) {
    sf::Vector2i p = pos(center);
    setPosition(p.x,p.y);
}

void Sprite::centerOrigin() {
  setOrigin(getTextureRect().width/2,getTextureRect().height/2);
}

void Sprite::render(sf::RenderTarget *t) {
  t->draw(*this);
}
