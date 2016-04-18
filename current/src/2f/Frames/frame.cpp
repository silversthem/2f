#include "../../../include/2f/Frames/Frame.hpp"

/* Protected */

void F2::Frame::frame(int const& width,int const& height,std::string const& name)
{
	setBounds(width,height);
	create(sf::VideoMode(width,height),name);
}

void F2::Frame::render()
{
	clear(sf::Color::Black); // @TODO : change that for a background
	render_map(&_stuff);
	display();
}

void F2::Frame::render_object(Object *o)
{
	EventMachine::applyEvent(o);
	o->onDisplay();
	draw(o->getDrawable());
}

void F2::Frame::render_map(Map *m)
{
	_stuff.foreach<F2::Frame,F2::Object>(this,&F2::Frame::render_object);
}

void F2::Frame::calculate_mouse_pos()
{
	_mouse.x = sf::Mouse::getPosition(*this).x;
	_mouse.y = sf::Mouse::getPosition(*this).y;
}

void F2::Frame::calculate_bounds()
{
	_bounds.x = getSize().x;
	_bounds.y = getSize().y;
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

void F2::Frame::onEvent(sf::Event *e)
{
	if(_event.type == sf::Event::Closed)
	{
		close();
	}
}

void F2::Frame::run()
{
	while(isOpen())
	{
		calculate_bounds();
		calculate_mouse_pos();
		while(pollEvent(_event))
		{
			handle();
			_stuff.foreach<F2::EventMachine,F2::Listener>(this,&F2::EventMachine::applyEvent);
		}
		render();
	}
	_stuff.apply<Listener>(&F2::Listener::onClose); // Closing the frame
}