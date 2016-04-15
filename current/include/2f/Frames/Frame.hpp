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
		sf::FloatRect _segment; // Segment of plan captured
		Timer _timer;           // Frame timer
		sf::Vector2f _mouse;    // Mouse position
		sf::Vector2f _bounds;   // Frame bounds = window size
		/* Methods */
		void frame(int const& width,int const& height,std::string const& name);
		void render();                    // Renders the frame
		void render(VECTOR(Object) v); // Renders objects in the frame
		void renderAll();                 // Forces the frame to render all things, even out of bounds
		/* Calculations */
		void calculate_mouse_pos(); // Calculate mouse pos in frame
		void calculate_bounds();    // Calculate frame bounds
	public:
		/* Constructors */
		Frame(); // Creates a frame
		Frame(int const& width,int const& height,std::string const& name); // Creates a sized frame
		/* Setters */
		void setSegmentStart(int const& x,int const& y); // Sets beginning of the captured segment
		void setSegmentSize(int const& w,int const& h);  // Sets size of the captured segment
		/* Methods */
		void onEvent(); // Frame events
		void run(); // Runs the frame
	};
};
