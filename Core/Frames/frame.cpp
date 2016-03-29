#include "Frame.hpp"

Frame::Frame()
{
	_bounds.x = 0;
	_bounds.y = 0;
	calculate_mouse_pos();
}

Frame::Frame(float const &width,float const &height,std::string const &title)
{
	makeFrame(width,height,title);
}

void Frame::makeFrame(float const &width,float const &height,std::string const &title)
{
	setBounds(width,height);
	create(sf::VideoMode(width,height),title);
	_bounds.x = width;
	_bounds.y = height;
	calculate_mouse_pos();
}

Frame::~Frame()
{
	
}

/* Adders */

void Frame::addObject(Object *object)
{
	addListener(object);
	Plan::addObject(object);
}

/* Pile methods */

void Frame::drawAll()
{
	clear(sf::Color::Black);
	Objects toDraw = objectsInBounds(sf::FloatRect(sf::Vector2f(0,0),_bounds));
	Objects::iterator it = toDraw.begin();
	for(;it != toDraw.end();it++)
	{
		(*it)->onDisplay();
		draw(*(*it)->getDrawable());
	}
	display();
}

/* Getters */

const sf::Vector2f& Frame::bounds() const
{
	return _bounds;
}

const sf::Vector2f& Frame::mouse() const
{
	return _mouse;
}

/* Running method */

void Frame::run()
{
	while(isOpen())
	{
		calculate_bounds();
		calculate_mouse_pos();
		while(pollEvent(_event))
		{
			eventHandling();
		}
		drawAll();
	}
}

void Frame::onClose()
{
	
}

/* Protected methods */

void Frame::addListener(Listener *listener)
{
	_listeners.push_back(listener);
}

void Frame::calculate_bounds()
{
	_bounds.x = getSize().x;
	_bounds.y = getSize().y;
}

void Frame::calculate_mouse_pos()
{
	_mouse.x = sf::Mouse::getPosition(*this).x;
	_mouse.y = sf::Mouse::getPosition(*this).y;
}

void Frame::eventHandling()
{
	if(_event.type == sf::Event::Closed) // Closing the window
	{
		onClose();
		close();
	}
	else
	{
		std::vector<Listener*>::iterator it = _listeners.begin();
		for(;it != _listeners.end();it++) // Parcouring each listener
		{
			call(*it);
		}
	}
}

void Frame::call(Listener* listener)
{
	switch(_event.type)
	{
		case sf::Event::MouseButtonPressed: // Mouse click
			listener->onMouseClicked(_event.mouseButton);
		break;
		case sf::Event::MouseButtonReleased: // Mouse released
			listener->onMouseReleased(_event.mouseButton);
		break;
		case sf::Event::MouseMoved: // Mouse move
			listener->onMouseMoved(_event.mouseMove);
		break;
		case sf::Event::KeyPressed: // Key pressed
			listener->onKeyPressed(_event.key);
		break;
		case sf::Event::KeyReleased: // Key released
			listener->onKeyReleased(_event.key);
		break;
		default:
		// Unhandled event, TODO : add a listener method to handle this case
		break;
	}
}