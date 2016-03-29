#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include <string>
#include <vector>
#include <map>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../Math/Plan.hpp"
#include "../Objects/Object.hpp"
#include "../Objects/Structure.hpp"
#include "../Objects/Shapes/Rectangle.hpp"
#include "../Time/Timer.hpp"
#include "../Listeners/ObjectListener.hpp"

/* SFML window with event handling */

class Frame : public sf::RenderWindow, public Plan
{
protected:
	sf::Event _event; // Event listener
	Timer _timer; // a timer
	/* Piles */
	std::vector<Listener*> _listeners; // listeners to events
	// Structures vector
	// Projectile vector (they're both displayed differently)
	// Shader vector ?
	// Widget vector
	/* Window info */
	sf::Vector2f _mouse; // Mouse position
	sf::Vector2f _bounds; // Window bounds
	/* Protected methods */
	void eventHandling(); // Handling events by calling listeners
	void displayAll(); // Display all things
	void calculate_bounds(); // Calculates window bounds
	void calculate_mouse_pos(); // Calculates mouse position in frame
	/* Event methods */
	void call(Listener* listener); // Calls appropriate events on a listener
	/* Adders */
	void addListener(Listener *listener); // Adds a listener
public:
	Frame(); // Creates a frame
	Frame(float const &width,float const &height,std::string const &title); // creates a frame
	void makeFrame(float const &width,float const &height,std::string const &title); // Creates the sfml renderwindow
	~Frame(); // Deleting dynamically allocated threads
	/* Adders */
	void addObject(Object *object);
	/* Pile methods */
	void drawAll(); // Drawing (sf::Drawable)
	// Structures drawing, events
	/* Getters */
	const sf::Vector2f& bounds() const; // Frame bounds
	const sf::Vector2f& mouse() const; // Returns mouse position
	/* Methods */
	virtual void run(); // runs window
	/* Events */
	virtual void onClose(); // What to do when closing the window
};

#endif