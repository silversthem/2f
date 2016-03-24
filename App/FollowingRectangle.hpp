#ifndef FOLLOWINGRECTANGLE
#define FOLLOWINGRECTANGLE

#include "TestRectangle.hpp"

class FollowingRectangle : public Rectangle
{
protected:
	Toward following; // Following movement
	float defaultspeed;
public:
	FollowingRectangle(Frame &frame,TestRectangle &rect,float const &speed = 0.3) // creates the rectangle
	{
		defaultspeed = speed;
		connect(&frame);
		setSpeed(speed);
		following.toward(rect.getPosition());
		setMovement(following);
	}
	void display() // Rotating the following rectangle towards the rectangle it's following
	{
		setRotation(Line(getPosition(),following.getPoint()).angle());
		std::vector<Object*> touched = frame()->objectsTouching(this);
		following.setApply(true);
		if(touched.size() > 1) // Touching too much stuff
		{
			following.setApply(false);
		}
		else if(touched.size() > 0) // Touching stuff
		{
			following.setAngle( // Chaning angle to avoid superposition
				Line(following.getPoint(),getPosition()).angle() - Line(touched[0]->getObjectPosition(),getPosition()).angle());
		}
		else // Not touching stuff
		{
			following.setAngle(0);
		}
	}
};

#endif