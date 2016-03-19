#include "Object.hpp"
#include "../Frames/Frame.hpp"

void Object::connect(Frame* frame)
{
	_Frame = frame;
}