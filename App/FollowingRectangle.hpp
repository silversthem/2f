#ifndef FOLLOWINGRECTANGLE
#define FOLLOWINGRECTANGLE

#include "TestRectangle.hpp"

class FollowingRectangle : public Rectangle
{
protected:
	Toward following; // Following movement
	float defaultspeed;
	Rectangle *_rect;
public:
	FollowingRectangle(Frame &frame,Rectangle &rect,float const &speed = 0.3) // creates the rectangle
	{
		_rect = &rect;
		defaultspeed = speed;
		connect(&frame);
		setSpeed(speed);
		following.toward(rect.getPosition());
		setMovement(following);
	}
	void display() // Rotating the following rectangle towards the rectangle it's following
	{
		setRotation(Line(getPosition(),following.getPoint()).angle());
		following.setApply(true);
		if(_rect->collision(this))
		{
			following.setApply(false);
		}
	}
};

#endif