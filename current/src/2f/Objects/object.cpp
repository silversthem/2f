#include "../../../include/2f/Objects/Object.hpp"
#include "../../../include/2f/Frames/Frame.hpp"
#include "../../../include/2f/Containers/Map.hpp"

void F2::Object::connect(F2::Frame* frame,F2::Map *m)
{
	_frame = frame;
	_map   = m;
}

F2::Object::~Object()
{
	if(_map != 0) // In a map
	{
		// Delete from map
	}
}

F2::Frame* F2::Object::frame()
{
	return _frame;
}