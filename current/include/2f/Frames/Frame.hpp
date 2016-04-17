/*
 * A frame is a window displaying a segment of a plan and answering to events.
 * A frame is also a listener, its events can be overwritten.
 * A frame also contains a timer.
 */

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
/* F2 */
#include "EventMachine.hpp"
#include "Plan.hpp"
#include "../Time/Timer.hpp"

namespace F2
{
	class Frame : public F2::Plan, public F2::EventMachine, public F2::Listener, public sf::RenderWindow
	{
	protected:
		sf::View _segment;      // Segment of window captured
		Timer _timer;           // Frame timer
		sf::Vector2f _mouse;    // Mouse position
		sf::Vector2f _bounds;   // Frame bounds = window size
		/* Methods */
		void frame(int const& width,int const& height,std::string const& name);
		void render(); // Renders the frame
		void render_object(Object *o);        // Renders an object
		void render_layer(Layer<Object> *l);  // Renders a layer
		void render_map(Map *m);              // Renders a map
		/* Calculations */
		void calculate_mouse_pos(); // Calculate mouse pos in frame
		void calculate_bounds();    // Calculate frame bounds
	public:
		/* Constructors */
		Frame(); // Creates a frame
		Frame(int const& width,int const& height,std::string const& name); // Creates a sized frame
		/* Methods */
		void onEvent(); // Frame events
		void run(); // Runs the frame
	};
};
