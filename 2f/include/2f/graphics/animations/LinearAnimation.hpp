/*

*/

#ifndef LINEARANIMATION_HPP
#define LINEARANIMATION_HPP

#include "../Animation.hpp"

namespace f2 {

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
  std::pair<sf::Texture*,sf::IntRect> get_frame(int const& n);
  std::pair<sf::Texture*,sf::IntRect> update(int const& nticks);
};

};

#endif
