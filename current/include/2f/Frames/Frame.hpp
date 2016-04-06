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
		/* Methods */
		void frame(int const& width,int const& height,std::string const& name);
		void render();                    // Renders the frame
		void render(VECTOR_OF(Object) v); // Renders objects in the frame
		void renderAll();                 // Forces the frame to render all things, even out of bounds
	public:
		/* Constructors */
		Frame(); // Creates a frame
		Frame(int const& width,int const& height,std::string const& name); // Creates a sized frame
		/* Adders */
		void addObject(F2::Object* o); // Adds an object
		/* Setters */
		void setSegmentStart(int const& x,int const& y); // Sets beginning of the captured segment
		void setSegmentSize(int const& w,int const& h);  // Sets size of the captured segment
		/* Getters */
		Timer* timer(); // Returns frame timer
		/* Methods */
		void onEvent(); // Frame events
		void run(); // Runs the frame
	};
};
