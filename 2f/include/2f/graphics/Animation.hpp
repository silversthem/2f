/*
  An animation is an chain of textures being displayed one after the other
  Transformations on existing textures are also possible
  This is an abstract class
*/

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "Texture.hpp"

namespace f2 {

class Animation : public Texture {
public:
  virtual void update(int const& nt, TextureStates const& sts) = 0;
};

};

#endif
