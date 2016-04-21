#include <iostream>

/* 2f files */
#include "include/2f/2f.hpp"

class Rect : public F2::Rectangle
{
protected:
	bool isAllowedToMove;
	int _speed;
public:
	Rect(int const& speed = 1,int const& x = 100)
	{
		_speed = speed;
		setPosition(sf::Vector2f(x,0));
		setFillColor(sf::Color::Blue);
		setSize(sf::Vector2f(50,50));
	}
	void onTicked(int const& tick)
	{
		if(tick > frame()->timer()->get_max_tick()/2 && tick % _speed == 0)
		{
			move(0,-1);
		}
		else if(tick < frame()->timer()->get_max_tick()/2 && tick % _speed == 0)
		{
			move(0,1);
		}
	}
	void onDisplay()
	{
		
	}
};

int main()
{
	F2::Frame f(550,550,"Test window"); // Creating a frame
	  f.timer()->set_tick_duration(10); // A tick is 10ms
	     f.timer()->set_max_tick(1000); // Returns to 0 every 1000 ticks
	            f.render_on_tick(true); // Only display once every tick (events are independant)

	F2::Layer<Rect> l; // Creating a layer of rectangles

	f.add_layer("rectangles",&l); // Adding the layer to the map

	Rect r;

	l.add(&r);

	f.run(); // Runs the frame, your job is done here

	return 0;
}