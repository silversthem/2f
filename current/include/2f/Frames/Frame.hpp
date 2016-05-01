/*
 * A frame is a window displaying a segment of a plan and answering to events.
 * A frame is also a listener, its events can be overwritten.
 * A frame also contains a timer.
 */

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
/* F2 */
#include "Plan.hpp"
#include "../Time/Timer.hpp"
#include "../Listeners/Listener.hpp"
#include "../macros.hpp"

#ifndef FRAME_HPP
#define FRAME_HPP

namespace F2
{
	class Frame : public F2::Plan, public sf::RenderWindow, public Listener
	{
	protected:
		sf::Event     _event; // Events in frame
		sf::View    _segment; // Segment of window captured
		Timer         _timer; // Frame timer
		int    _current_tick; // Copy of the current tick
		sf::Vector2f  _mouse; // Mouse position
		sf::Vector2f _bounds; // Frame bounds = window size
		bool _render_on_tick; // If we have to wait for the timer to update to render
		/* Methods */
		void onInit(); // Initialize the frame
		void frame(int const& width,int const& height,std::string const& name); // Displays a frame
		void render(); // Renders the frame
		void render_object(Object *o);        // Renders an object
		void render_map(Map *m);              // Renders a map
		/* Calculations */
		void calculate_mouse_pos(); // Calculate mouse pos in frame
		void calculate_bounds();    // Calculate frame bounds
	public:
		/* Constructors */
		Frame(); // Creates a frame
		Frame(int const& width,int const& height,std::string const& name); // Creates a sized frame
		/* Adders */
		template <typename T>
		void add(std::string const& name,T *o) // Adds an object in the plan
		{
			_stuff.add(name,o);
			o->onInit();
		}
		template <typename T>
		void add_layer(std::string const& name, Layer<T> *o) // Adds a layer of objects
		{
			_stuff.add_layer<T>(name,o);
		}
		void add_map(); // @TODO : Adds a map of layers and objects
		/* Setters */
		void render_on_tick(bool const& state); // if we should render on tick 
		/* Getters */
		Timer* timer(); // Returns timer
		int get_current_tick(); // Returns current tick
		const sf::Vector2f& getBounds() const; // Returns frame's size
		const sf::Vector2f& getMouse()  const; // Returns mouse's position
		/* Methods */
		void otherEvent(sf::Event *e); // Frame events
		void run(); // Runs the frame
	};
};

#endif