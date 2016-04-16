#include "../../../include/2f/Frames/Frame.hpp"

/* Protected */

void F2::Frame::frame(int const& width,int const& height,std::string const& name)
{
	setBounds(width,height);
	create(sf::VideoMode(width,height),name);
}

void F2::Frame::render()
{
	
}

/* Constructors */

F2::Frame::Frame()
{
	setBounds(0,0);
}

F2::Frame::Frame(int const& width,int const& height,std::string const& name)
{
	frame(width,height,name);
}

/* Adders */



/* Methods */

void F2::Frame::onEvent()
{
	
}

void F2::Frame::run()
{
	
}