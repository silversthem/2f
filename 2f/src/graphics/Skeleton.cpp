#include "2f/graphics/Skeleton.hpp"

using namespace f2;

Skeleton::Skeleton() {

}

void Skeleton::foreach(std::function<void (SkeletonPart&)> f) {
  SkeletonDict::iterator it = skeleton.begin();
  for(; it != skeleton.end(); it++) {
    f(it->second);
  }
}

void Skeleton::setScale(float const& x, float const& y) {
  foreach([x,y](SkeletonPart& sp){
    sp.second->setScale(x,y);
  });
}

void Skeleton::add(std::string const& name, sf::Vector2i const& pos, Texture *t) {
  skeleton[name] = SkeletonPart(pos,t);
}

Texture* Skeleton::texture(std::string const& name) {
  SkeletonDict::iterator r = skeleton.find(name);
  return (r != skeleton.end()) ? r->second.second : 0;
}

void Skeleton::update(int const& nt) {
  foreach([nt](SkeletonPart& sp) {
    sp.second->update(nt);
  });
}

void Skeleton::blit(sf::RenderTarget *rt,sf::Vector2i const& pos) {
  foreach([rt,pos](SkeletonPart& sp) {
    sp.second->blit(rt,pos + sp.first);
  });
}
