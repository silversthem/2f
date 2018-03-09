#include "../../../include/2f/Frames/Plan.hpp"

/* Constructors */

F2::Plan::Plan()
{
	setBounds(0,0);
}

F2::Plan::Plan(int const& width,int const& height)
{
	setBounds(width,height);
}
/* Setters */

void F2::Plan::setBounds(int const& width,int const& height)
{
	_bounds.top    = 0;
	_bounds.left   = 0;
	_bounds.width  = width;
	_bounds.height = height;
}

/* Getters */

F2::Map* F2::Plan::map()
{
	return &_stuff;
}