#include "2f/gui/Frame.hpp"

using namespace f2;

Frame::Frame() : entities(Indexer::IndexerType::Hash), newticks(0), center(0), rotateCenter(false) {

}

void Frame::centerAround(Entity *e, bool rotate) {
  center = e;
  rotateCenter = rotate;
}

void Frame::setBounds(int const& w, int const& h) {
  bounds = sf::IntRect(0,0,w,h);
}

void Frame::handle(sf::Event const &e) {
  eventHandler.handle(e);
}

void Frame::calc(int const& nt) {
  newticks = nt; // Updating newticks to render
  update(nt);
}

bool Frame::inBounds(sf::IntRect const& bonds) {

}

#include <iostream>
void Frame::render(sf::RenderTarget *target) { // Rendering as object in frame
  int nt = newticks;
  Entity* center = Frame::center;
  int orientation = (rotateCenter && center != 0) ? center->getOrientation() : 0;
  sf::IntRect bounds = Frame::bounds;
  if(center != 0) bg.render(target,bounds,center->getCoords());
  /* Parcouring entities */
  entities.foreach<Object>([target,nt,center,bounds,orientation](Object *o) {
    /* Positioning relative to entity center */
    if(center != 0 && o != center) {
      o->relativePosition(center->getCoords() + sf::Vector2i(-bounds.width/2,-bounds.height/2), -orientation);
    } else if(o == center) {
      o->relativePosition(center->getCoords() + sf::Vector2i(-bounds.width/2,-bounds.height/2), 0);
    }
    else {
      o->relativePosition(sf::Vector2i(-bounds.width/2,-bounds.height/2), 0);
    }
    o->calc(nt); // Updating object
    // Rendering object
    o->render(target);
  });
}

void Frame::render(sf::RenderTarget *t,int const& nt) { // Rendering as main frame
  newticks = nt;
  calc(nt);
  render(t);
}

Indexer* Frame::indexer() {
  return &entities;
}

EventHandler* Frame::handler() {
  return &eventHandler;
}

Background* Frame::background() {
  return &bg;
}
