#include "2f/gui/Frame.hpp"

using namespace f2;

Frame::Frame() : entities(Indexer::IndexerType::Hash), newticks(0), center(0), centerMid(true) {

}

void Frame::centerAround(Entity *e) {
  center = e;
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

void Frame::render(sf::RenderTarget *target) { // Rendering as object in frame
  int nt = newticks;
  Entity* center = Frame::center;
  sf::IntRect bounds = Frame::bounds;
  /* Parcouring entities */
  entities.foreach<Object>([target,nt,center,bounds](Object *o) {
    o->calc(nt); // Updating object
    /* Positioning relative to entity center */
    if(center != 0) {
      o->relativePosition(center->getCoords());
    } else {
      o->relativePosition(sf::Vector2i(0,0));
    }
    o->relativePosition(sf::Vector2i(-bounds.width/2,-bounds.height/2));
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
