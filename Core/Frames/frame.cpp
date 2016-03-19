#include "Frame.hpp"

Frame::Frame(float const &width,float const &height,std::string const &title)
{
	_changed = true;
	create(sf::VideoMode(width,height),title);
}

Frame::~Frame()
{
	
}

/* Public : Adders */

void Frame::addRectangle(Rectangle& rect)
{
	add_to_pile(rect,rect);
}

/* Running method */

void Frame::run()
{
	/* Note to self : Separate methods for handling pauses and later, only "exec" when needing to refresh content */
	while(isOpen())
	{
		clear();
		while(pollEvent(_event))
		{
			eventHandling();
		}
		displayAll();
	}
}

void Frame::onClose()
{
	
}

/* Protected methods */

void Frame::add_to_pile(sf::Drawable &d,Object &o)
{
	o.connect(this);
	_objects[&d] = &o;
}

void Frame::eventHandling()
{
	std::map<sf::Drawable*,Object*>::iterator it = _objects.begin();
	if(_event.type == sf::Event::Closed)
	{
		close();
	}
	else
	{
		for(;it != _objects.end();it++)
		{
			if(it->second != NULL)
			{
				switch(_event.type)
				{
					case sf::Event::MouseButtonPressed:
						it->second->onMouseClicked(_event.mouseButton);
					break;
					case sf::Event::MouseButtonReleased:
						it->second->onMouseReleased(_event.mouseButton);
					break;
					case sf::Event::MouseMoved:
						it->second->onMouseMoved(_event.mouseMove);
					break;
					case sf::Event::KeyPressed:
						it->second->onKeyPressed(_event.key);
					break;
					case sf::Event::KeyReleased:
						it->second->onKeyReleased(_event.key);
					break;
					default:
						// Unhandled event, todo : add a listener method to handle this case
					break;
				}
			}
		}
	}
}

void Frame::displayAll()
{
	std::map<sf::Drawable*,Object*>::iterator it = _objects.begin();
	for(;it != _objects.end();it++)
	{
		if(it->second != NULL) // We're drawing an object
		{
			it->second->onDisplay(); // Calling onDisplay method
		}
		draw(*it->first);
	}
	display();
}