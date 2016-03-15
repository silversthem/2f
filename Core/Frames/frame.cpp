#include "Frame.hpp"

Frame::Frame(float const &width,float const &height,std::string const &title)
{
	_changed = true;
	create(sf::VideoMode(width,height),title);
}

Frame::~Frame()
{
	
}

/* Protected : Adders */

void Frame::addToPile(sf::Drawable& draw,Object& o)
{
	_elements[&draw] = &o;
}

/* Public : Adders */

void Frame::addRectangle(Rectangle& rect)
{
	addToPile(rect,rect);
}

void Frame::run()
{
	std::map<sf::Drawable*,Object*>::iterator it = _elements.begin();
	while(pollEvent(_event))
	{
		if(_event.type == sf::Event::Closed)
		{
			close();
		}
		for(;it != _elements.end();it++)
		{
			if(it->second != NULL)
			{
				it->second->onEvent(_event);
			}
			if(it->first != NULL)
			{
				draw(*it->first);
			}
		}
	}
	display();
}