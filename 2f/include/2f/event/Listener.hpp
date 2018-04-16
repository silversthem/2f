/*
  A listener is an object capable of event interaction
  through a subscribe bind pattern
*/

#ifndef LISTENER_HPP
#define LISTENER_HPP

namespace f2 {

class Listener {
protected:

public:
  /* mouse events */
  virtual void onClicked();
  virtual void onClick();
  virtual void onMouseMoved(int const& x, int const& y);
  /* key events */
  virtual void onKeyPressed(int const& kcode);
  virtual void onKeyReleased(int const& kcode);
};

}

#include <set>
#include <map>

typedef std::set<f2::Listener*> Listeners;
typedef std::map<int,std::set<f2::Listener*> > EventListeners;

#endif
