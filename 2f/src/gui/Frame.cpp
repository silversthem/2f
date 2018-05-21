#include "2f/gui/Frame.hpp"

using namespace f2;

Frame::Frame() : newticks(0), center(0), rotateCenter(false) {
  eventHandler.subscribe(sf::Event::KeyPressed,&keyboard);
  eventHandler.subscribe(sf::Event::KeyReleased,&keyboard);
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
  /* Lambda arguments references */
  int nt = newticks;
  Entity* center = Frame::center;
  sf::IntRect bounds = Frame::bounds;
  /* Callibrating view & background */
  float orientation = 0;
  sf::Vector2i centerCoords = sf::Vector2i(0,0);
  if(center != 0) {
    centerCoords = center->getCoords();
    if(rotateCenter) {
      orientation = center->getOrientation();
    }
  }
  view.setRotation(orientation);
  bg.render(target,bounds,centerCoords,rotateCenter);
  view.setCenter(bounds.width/2,bounds.height/2);
  target->setView(view);
  /* Parcouring entities */
  entities.foreach<Object>([target,nt,center,bounds,orientation,centerCoords](Object *o) {
    /* Positioning relative to entity center and orientation */
    if(o == center) {
      o->relativePosition(centerCoords, sf::Vector2i(-bounds.width/2,-bounds.height/2), 0);
    }
    else {
      o->relativePosition(centerCoords, sf::Vector2i(-bounds.width/2,-bounds.height/2), -orientation);
    }
    o->calc(nt); // Updating object
    o->render(target); // Rendering object
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
