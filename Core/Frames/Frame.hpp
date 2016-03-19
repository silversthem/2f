#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include <string>
#include <vector>
#include <map>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../Objects/Object.hpp"
#include "../Objects/Structure.hpp"
#include "../Objects/Shapes/Rectangle.hpp"
#include "../Time/Timer.hpp"
#include "../Listeners/ObjectListener.hpp"

/* SFML window with event handling */

class Frame : public sf::RenderWindow
{
protected:
	sf::Event _event; // Event listener
	Timer _timer; // a timer
	std::map<sf::Drawable*,Object*> _objects; // Objects in plan
	bool _changed; // If there's need to re-draw things
	/* Protected methods */
	void add_to_pile(sf::Drawable &d,Object &o); // Adding to the object pile
	void eventHandling(); // Handling events by calling listeners
	void displayAll(); // Display all things
public:
	Frame(float const &width,float const &height,std::string const &title); // creates a frame
	~Frame(); // Deletes all elements structures in the frame
	/* Adders */
	void addSprite();
	/* Adders for shapes */
	void addShape();
	void addRectangle(Rectangle &rect); // adds a rectangle
	/* Calculations */
	/* Testers */
	/* Methods */
	void run(); // runs window
	/* Events */
	virtual void onClose(); // What to do when closing the window
};

#endif