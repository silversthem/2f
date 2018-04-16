/*

*/

#ifndef LINEARANIMATION_HPP
#define LINEARANIMATION_HPP

#include "../Animation.hpp"

namespace f2 {

namespace Animations {

class LinearAnimation : public Animation {
protected:
  sf::Texture *texture;
  sf::Vector2u box;
  sf::Vector2u frames;
  int delta; // time between two frames, in gameticks
  int currentdelta;
  int currentframe;
public:
  LinearAnimation(sf::Texture *t, int const& w, int const& h, int const& cols, int const& lines, int const& timing);
  virtual void update(int const& nticks);
};

};

};

#endif
