#include "2f/gui/Frame.hpp"

using namespace f2;

Frame::Frame() : entities(Indexer::IndexerType::Hash), newticks(0) {

}

void Frame::handle(sf::Event const &e) {

}

void Frame::calc(int const& nt) {
  newticks = nt; // Updating newticks to render
  update(nt);
}

bool Frame::inBounds(sf::IntRect const& bonds) {

}

void Frame::render(sf::RenderTarget *target) { // Rendering as object in frame
  int nt = newticks;
  /* Parcouring entities */
  entities.foreach<Object>([target,nt](Object *o) {
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
