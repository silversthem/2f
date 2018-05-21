#include "2f/objects/entities/Sprite.hpp"
#include <iostream>
using namespace f2;

Sprite::Sprite() : Entity() {

}

bool Sprite::inBounds(sf::IntRect const& r) {

}

void Sprite::render(sf::RenderTarget *t) {
  setPosition(frame_pos.x,frame_pos.y);
  setRotation(getOrientation());
  Texture::blit(t,sf::Vector2i(getPosition()));
}
