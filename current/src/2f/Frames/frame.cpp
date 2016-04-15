#include "../../../include/2f/Frames/Frame.hpp"

/* Protected */

void F2::Frame::frame(int const& width,int const& height,std::string const& name)
{
	setSegmentStart(0,0);
	setSegmentSize(width,height);
	setBounds(width,height);
	create(sf::VideoMode(width,height),name);
}

void F2::Frame::render()
{
	
}

void F2::Frame::render(VECTOR(F2::Object) v)
{
	clear(sf::Color::Black);
	
	display();
}

void F2::Frame::renderAll()
{
	
}

/* Constructors */

F2::Frame::Frame()
{
	setSegmentStart(0,0);
	setSegmentSize(0,0);
	setBounds(0,0);
}

F2::Frame::Frame(int const& width,int const& height,std::string const& name)
{
	frame(width,height,name);
}

/* Adders */



/* Setters */

void F2::Frame::setSegmentStart(int const& x,int const& y)
{
	_segment.top  = y;
	_segment.left = x;
}

void F2::Frame::setSegmentSize(int const& w,int const& h)
{
	_segment.width  = w;
	_segment.height = h;
}

/* Methods */

void F2::Frame::onEvent()
{
	
}

void F2::Frame::run()
{
	
}