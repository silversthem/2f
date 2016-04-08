#include "../../../include/2f/Frames/Frame.hpp"

/* Protected */

void F2::Frame::frame(int const& width,int const& height,std::string const& name)
{
	setSegmentStart(0,0);
	setSegmentSize(width,height);
	setBounds(width,height);
	addListener(this);
	create(sf::VideoMode(width,height),name);
}

void F2::Frame::render()
{
	render(Plan::getInBounds(_segment));
}

void F2::Frame::render(VECTOR_OF(F2::Object) v)
{
	clear(sf::Color::Black);
	VECTOR_OF(F2::Object)::iterator it = v.begin();
	for(;it != v.end();it++)
	{
		if(!(*it)->isDeleting())
		{
			(*it)->onDisplay();
			draw((*it)->getDrawable());
		}
	}
	display();
}

void F2::Frame::renderAll()
{
	render(_objects);
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

void F2::Frame::addObject(F2::Object* o)
{
	Plan::addObject(o);
	EventMachine::addListener(o);
	o->onInit();
}

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

/* Getters */



/* Methods */

void F2::Frame::onEvent()
{
	if(_event.type == sf::Event::Closed) // Closing the frame
	{
		sf::RenderWindow::close();
	}
}

void F2::Frame::run()
{
	onInit();
	while(isOpen())
	{
		while(pollEvent(_event))
		{
			EventMachine::handle();
		}
		onDisplay();
		render();
	}
	EventMachine::close();
}