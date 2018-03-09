#include "../../../include/2f/Objects/Object.hpp"
#include "../../../include/2f/Frames/Frame.hpp"
#include "../../../include/2f/Containers/Map.hpp"

F2::Object::Object()
{
	
}

F2::Object::~Object()
{
	delete_from_bound(this);
}

void F2::Object::onClose()
{
	close();
}