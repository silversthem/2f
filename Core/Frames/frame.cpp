#include "Frame.hpp"

Frame::Frame(float const &width,float const &height,std::string const &title)
{
	create(sf::VideoMode(width,height),title);
	_bounds.x = width;
	_bounds.y = height;
	calculate_mouse_pos();
}

Frame::~Frame()
{
	
}

/* Pile methods */

void Frame::drawAll()
{
	clear(sf::Color::Black);
	std::vector<sf::Drawable*>::iterator it = _drawables.begin();
	for(;it != _drawables.end();it++)
	{
		draw(*(*it));
	}
	display();
}

void Frame::calculateAll()
{
	std::vector<Object*>::iterator it = _objects.begin();
	for(;it != _objects.end();it++)
	{
		/* Object Events */
		if((*it)->isIn(mouse())) // Mouse touches object
		{
			(*it)->mouseTouched();
		}
		else if((*it)->mouseTouches()) // Mouse touched object, but doesn't anymore
		{
			(*it)->mouseLeft();
		}
		(*it)->onDisplay();
	}
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

/* Public : Adders */

void Frame::addDrawable(sf::Drawable *drawable)
{
	_drawables.push_back(drawable);
}

void Frame::addListener(Listener *listener)
{
	_listeners.push_back(listener);
}

void Frame::addObject(Object *object)
{
	object->onInit();
	_objects.push_back(object);
}

void Frame::addRectangle(Rectangle& rect)
{
	addDrawable(&rect);
	addListener(&rect);
	addObject(&rect);
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
		calculateAll();
		drawAll();
	}
	onClose();
}

void Frame::onClose()
{
	
}

/* Protected methods */

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