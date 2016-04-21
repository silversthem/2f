#include "../../../include/2f/Objects/Object.hpp"
#include "../../../include/2f/Frames/Frame.hpp"
#include "../../../include/2f/Containers/Map.hpp"

F2::Object::Object()
{
	
}

F2::Object::~Object()
{
	// If still connected to a layer/map, deconnect from it
}

void F2::Object::onClose()
{
	close();
}