#include "2f/event/KeyBoard.hpp"

using namespace f2;

KeyBoard::KeyBoard() {

}

void KeyBoard::setKeyStates(int const& kcode, std::function<void()> onPressed, std::function<void()> onReleased) {
  keyStates.insert(std::pair<int,KeyState>(kcode,KeyState(onPressed,onReleased)));
}

void KeyBoard::onKeyPressed(int const& kcode) {
  KeyStates::iterator it = keyStates.lower_bound(kcode);
  if(it != keyStates.end()) {
    while(it->first == kcode) {
      it->second.first();
      it++;
    }
  }
}

void KeyBoard::onKeyReleased(int const& kcode) {
  KeyStates::iterator it = keyStates.lower_bound(kcode);
  if(it != keyStates.end()) {
    while(it->first == kcode) {
      it->second.second();
      it++;
    }
  }
}
