/*

@TODO : Add timed repeated keypress
*/

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "Listener.hpp"
#include <map>
#include <functional>

namespace f2 {

typedef std::pair<std::function<void()>, std::function<void()> > KeyState;
typedef std::multimap<int,KeyState> KeyStates;

class KeyBoard : public Listener {
protected:
  KeyStates keyStates;
public:
  KeyBoard();
  /* Methods */
  void setKeyStates(int const& kcode, std::function<void()> onPressed, std::function<void()> onReleased);
  virtual void onKeyPressed(int const& kcode);
  virtual void onKeyReleased(int const& kcode);
};

};

#endif
