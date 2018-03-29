#include "2f/graphics/animations/LinearAnimation.hpp"

using namespace f2;

LinearAnimation::LinearAnimation(sf::Texture *t, int const& w, int const& h, int const& cols, int const& lines, int const& timing) {
  texture = t;
  box.x = w;
  box.y = h;
  frames.x = cols;
  frames.y = lines;
  delta = timing;
  currentdelta = 0;
  currentframe = 0;
}

std::pair<sf::Texture*,sf::IntRect> LinearAnimation::get_frame(int const& n) {

}

std::pair<sf::Texture*,sf::IntRect> LinearAnimation::update(int const& nticks) {
  std::pair<sf::Texture*,sf::IntRect> r;
  r.first = texture;
  currentdelta += nticks;
  if (currentdelta < 0) { // Anti cycle
    currentdelta += frames.x*frames.y;
  }
  if(currentdelta >= delta) { // Normal cycle
    currentframe += currentdelta/delta;
    currentdelta = currentdelta % delta;
  }
  if(currentframe >= frames.x * frames.y) {
    currentframe = currentframe % (frames.x * frames.y);
  }
  r.second = sf::IntRect((currentframe % frames.x)*box.x,(currentframe/frames.x)*box.y,box.x,box.y);
  return r;
}
