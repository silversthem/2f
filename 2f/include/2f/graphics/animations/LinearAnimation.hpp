/*

*/

#ifndef LINEARANIMATION_HPP
#define LINEARANIMATION_HPP

#include "../Animation.hpp"
#include "../Tileset.hpp"

namespace f2 {

namespace Animations {

class LinearAnimation : public Tileset {
protected:
  int delta; // time between two frames, in gameticks
  int currentdelta;
  int currentframe;
public:
  /* Constructors */
  LinearAnimation(sf::Texture *t, int const& w, int const& h, int const& cols, int const& lines, int const& timing);
  /* Setters */
  void setInterval(int const& interval);
  /* Methods */
  virtual void update(int const& nticks, TextureStates const& sts);
};

};

};

#endif
