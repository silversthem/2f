#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include <string>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../Objects/Object.hpp"
#include "../Objects/Shapes/Rectangle.hpp"
#include "../Time/Timer.hpp"
#include "../Listeners/ObjectListener.hpp"

/* SFML window with event handling */

struct Element // Structure containing a pointer to all the things handled by the frame
{
	sf::Drawable *drawable;
	Object *object;
	Listener *listener;
};

class Frame : public sf::RenderWindow
{
protected:
	sf::Event _event; // Event listener
	Timer _timer; // a timer
	std::vector<Element*> _elements; // elements in plan
public:
	Frame(float const &width,float const &height,std::string const &title); // creates a frame
	~Frame(); // Deletes all elements structures in the frame
	/* Adders */
	void addSprite();
	/* Adders for shapes */
	void addShape();
	void addRectangle(Rectangle const& rect); // adds a rectangle
	/* Calculations */
	/* Testers */
	/* Methods */
	void run(); // runs window
};

#endif