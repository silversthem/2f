#include <iostream>

/* 2f files */
#include "include/2f/2f.hpp"

class Rect : public F2::Rectangle
{
protected:
	bool isAllowedToMove;
public:
	Rect()
	{
		setPosition(sf::Vector2f(100,0));
		setFillColor(sf::Color::Blue);
		setSize(sf::Vector2f(50,50));
	}
	void onTicked(int const& tick)
	{
		if(tick > frame()->timer()->get_max_tick()/2)
		{
			move(0,-1);
		}
		else if(tick < frame()->timer()->get_max_tick()/2)
		{
			move(0,1);
		}
	}
};

int main()
{
	F2::Frame f(550,550,"Test window"); // Creating a frame
	  f.timer()->set_tick_duration(10); // A tick is 10ms
	     f.timer()->set_max_tick(1000); // Returns to 0 every 1000 ticks
	            f.render_on_tick(true); // Only display once every tick (events are independant)

	Rect r; // Creates a rectangle

	f.add("my_rectangle",&r); // Binds rectangle to the frame (adds it in the map)

	f.run(); // Runs the frame, your job is done here

	return 0;
}