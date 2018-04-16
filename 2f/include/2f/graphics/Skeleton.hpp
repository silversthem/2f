#ifndef SKELETON_HPP
#define SKELETON_HPP

#include <unordered_map>
#include <string>
#include <utility>
#include <functional>
#include "Texture.hpp"

namespace f2 {

typedef std::pair<sf::Vector2i,Texture*> SkeletonPart;
typedef std::unordered_map<std::string,SkeletonPart> SkeletonDict;

class Skeleton {
protected:
  SkeletonDict skeleton;
public:
  /* Constructors */
  Skeleton();
  /* Skeleton Dict methods */
  Texture* texture(std::string const& name);
  void add(std::string const& name, sf::Vector2i const& pos, Texture *t);
  void setScale(float const& x, float const& y);
  void foreach(std::function<void (SkeletonPart&)> f);
  /* Texture methods */
  void update(int const& nt);
  void blit(sf::RenderTarget *rt,sf::Vector2i const& pos);
};

};

#endif
