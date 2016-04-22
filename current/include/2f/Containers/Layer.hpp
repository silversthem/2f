/*
 * A layer is a collection of objects stored as their real type (no downcasting)
 * Layers are contained in map
 * Layers can use collision and detection methods with other objects
 */

#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>
/* 2f */
#include "../Binders/FrameBinder.hpp"

namespace F2
{
	class Map; // Injection
	class Frame; // Parent frame

	template<typename ObjectType,typename Parent = Map*>
	class Layer : public FrameBinder
	{
	protected:
		std::vector<ObjectType*> _objects; // Objects of the layers
		Parent _map; // Layer map
		Frame *_frame; // Layer Frame, for connection
	public:
		Layer()  // Creates a layer
		{
			
		}
		~Layer()
		{
			typename std::vector<ObjectType*>::iterator it = _objects.begin();
			for(;it != _objects.end();it++)
			{
				(*it)->unbind();
			}
		}
		/* Methods */
		void add(ObjectType *o) // Adds an object in the layer
		{
			o->connect(frame());
			o->bind_to_layer(this);
			_objects.push_back(o);
		}
		std::vector<ObjectType*>* vector() // Returns the vector
		{
			return &_objects;
		}
		void del(ObjectType *o) // Deletes an element
		{
			typename std::vector<ObjectType*>::iterator it = _objects.begin();
			for(;it != _objects.end();)
			{
				if(*it == o)
				{
					_objects.erase(it);
				}
				else
				{
					it++;
				}
			}
		}
		/* Container methods */
		template<class In>
		void foreach(In *c,void (In::*action)(ObjectType*)) // Applies a method to every layer element
		{
			for(unsigned int i = 0;i < _objects.size();i++)
			{
				(c->*action)(_objects[i]);
			}
		}
		template<typename OtherArg>
		void apply(void (ObjectType::*action)(OtherArg),OtherArg *a) // Uses a method from each element
		{
			for(unsigned int i = 0;i < _objects.size();i++)
			{
				(_objects[i]->*action)(a);
			}
		}
		void apply(void (ObjectType::*action)()) // Uses a method from each object, without argument
		{
			for(unsigned int i = 0;i < _objects.size();i++)
			{
				(_objects[i]->*action)();
			}
		}
	};
};

#endif