#include "2f/graphics/animations/LinearAnimation.hpp"

using namespace f2;
using namespace f2::Animations;

LinearAnimation::LinearAnimation(sf::Texture *t, int const& w, int const& h, int const& cols, int const& lines, int const& timing)
  : Tileset(t,sf::Vector2u(w,h),sf::Vector2u(cols,lines))
  {
  delta = timing;
  currentdelta = 0;
  currentframe = 0;
}

void LinearAnimation::setInterval(int const& interval) {
  delta = interval;
}

void LinearAnimation::update(int const& nticks, TextureStates const& sts) {
  currentdelta += nticks;
  if (currentdelta < 0) { // Anti cycle
    currentdelta += frames.x*frames.y;
  }
  if(currentdelta >= delta) { // Normal cycle
    currentframe += currentdelta/delta;
    currentdelta = currentdelta % delta;
  }
  tile(currentframe);
}
