#include "../../../include/2f/Frames/Frame.hpp"

/* Protected */

void F2::Frame::onInit()
{
	_render_on_tick = false;
	map()->connect(this);
	init();
}

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
	if(_timer.is_set() && _timer.updated())
	{
		o->onTicked(_current_tick);
	}
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
	onInit();
	setBounds(0,0);
}

F2::Frame::Frame(int const& width,int const& height,std::string const& name)
{
	onInit();
	frame(width,height,name);
}

/* Setters */

void F2::Frame::render_on_tick(bool const& state)
{
	_render_on_tick = state;
}

/* Getters */

F2::Timer* F2::Frame::timer()
{
	return &_timer;
}

int F2::Frame::get_current_tick()
{
	return _current_tick;
}

const sf::Vector2f& F2::Frame::getBounds() const
{
	return _bounds;
}

const sf::Vector2f& F2::Frame::getMouse() const
{
	return _mouse;
}

/* Methods */

void F2::Frame::onEvent(sf::Event *e)
{
	if(_event.type == sf::Event::Closed)
	{
		sf::RenderWindow::close();
	}
}

void F2::Frame::run()
{
	_timer.start();
	while(isOpen())
	{
		calculate_bounds();
		calculate_mouse_pos();
		while(pollEvent(_event))
		{
			handle();
			_stuff.foreach<F2::EventMachine,F2::Listener>(this,&F2::EventMachine::applyEvent);
		}
		if(_timer.is_set())
		{
			_current_tick = _timer.get_tick();
		}
		if(!_render_on_tick || _timer.updated()) // If we don't render on tick or the tick count has updated
		{
			render();
		}
	}
	onClose();
	_stuff.apply<Listener>(&F2::Listener::onClose); // Closing the frame /!\ Disconnecting objects before disconnecting their layers
}