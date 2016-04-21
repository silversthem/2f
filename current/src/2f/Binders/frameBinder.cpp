#include "../../../include/2f/Binders/FrameBinder.hpp"
#include "../../../include/2f/Containers/Layer.hpp"
#include "../../../include/2f/Containers/Map.hpp"

F2::FrameBinder::FrameBinder()
{
	_bind = F2::FrameBinder::None;
	_frame = 0;
}

void F2::FrameBinder::connect(Frame *f)
{
	_frame = f;
}

void F2::FrameBinder::disconnect()
{
	_frame = 0;
}

/* Binding */

void F2::FrameBinder::bind_to_map(Map *m)
{
	_bind = F2::FrameBinder::ToMap;
	_map = m;
}

void F2::FrameBinder::bind_to_layer(void* l)
{
	_bind = F2::FrameBinder::ToLayer;
	_layer = l;
}

/* Unbinding */

void F2::FrameBinder::delete_from_bound()
{
	switch(_bind)
	{
		case F2::FrameBinder::ToLayer:
			layer<F2::FrameBinder>()->del(this);
		break;
		case F2::FrameBinder::ToMap:
			map()->del(this);
		break;
		default:
			// ...
		break;
	}
}

void F2::FrameBinder::unbind()
{
	_bind = F2::FrameBinder::None;
}

/* Getters */

F2::Map* F2::FrameBinder::map()
{
	// @TODO : Check type
	return _map;
}

F2::Frame* F2::FrameBinder::frame()
{
	// @TODO : Check if connected
	return _frame;
}