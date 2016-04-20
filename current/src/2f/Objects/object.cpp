#include "../../../include/2f/Objects/Object.hpp"
#include "../../../include/2f/Frames/Frame.hpp"
#include "../../../include/2f/Containers/Map.hpp"

void F2::Object::delete_from_container()
{
	if(_l != 0) // In a layer
	{
		_l->del(this);
	}
	if(_map != 0) // In a map
	{
		_map->del(this);
	}
	_map = 0;
	_l   = 0;
}

F2::Object::Object()
{
	_frame = 0;
	_map   = 0;
	_l     = 0;
}

/* Connections */

void F2::Object::connect_to_frame(Frame *frame)
{
	_frame = frame;
}

void F2::Object::connect_to_map(Map *map)
{
	_map = map;
}

void F2::Object::connect_to_layer(Layer<Object>* l)
{
	_l = l;
}

F2::Object::~Object()
{
	delete_from_container();
}

void F2::Object::onClose()
{
	close();
	delete_from_container();
}

F2::Frame* F2::Object::frame()
{
	return _frame;
}

F2::Map* F2::Object::map()
{
	return _map;
}

F2::Layer<F2::Object,F2::Map*>* F2::Object::layer()
{
	return _l;
} 