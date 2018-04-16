#include "2f/graphics/animations/LinearAnimation.hpp"

using namespace f2;
using namespace f2::Animations;

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

void LinearAnimation::update(int const& nticks) {
  setTexture(*texture);
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
  setTextureRect(sf::IntRect((currentframe % frames.x)*box.x,(currentframe/frames.x)*box.y,box.x,box.y));
}
