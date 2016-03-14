#ifndef LISTENER_HPP_INCLUDED
#define LISTENER_HPP_INCLUDED

/* A listener is called when event are produced */

#include <SFML/Window/Event.hpp>

enum ClickType {Left,Right,MouseWheel};

class Listener
{
public: // events
	void onEvent(sf::Event const &event); // basic event
	void onMouseClicked(sf::Mouse const &mouse); // on click
	void onMouseReleased(sf::Mouse const &mouse); // on click
	void onKeyPressed(sf::Keyboard const &keyPressed); // on key pressed
	void onKeyReleased(sf::Keyboard const &keyPressed); // on key released
};

#endif