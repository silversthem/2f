/*
 * A layer is a collection of objects stored as their real type (no downcasting)
 * Layers are contained in map
 * Layers can use collision and detection methods with other objects
 */

#ifndef LAYER_HPP
#define LAYER_HPP

#include <algorithm>
#include <functional>
#include <vector>
/* 2f */
#include "../Binders/FrameBinder.hpp"

namespace F2
{
	template<typename ObjectType,typename Parent = Map*>
	class Layer : public FrameBinder<Map*,void*>
	{
	protected:
		std::vector<ObjectType*> _objects; // Objects of the layers
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
			delete_from_bound(this);
		}
		/* Methods */
		void add(ObjectType *o) // Adds an object in the layer
		{
			o->connect(frame());
			o->bind_to_layer(this);
			o->onInit();
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
		void walk(std::function<void (ObjectType*)> const& f) // Applies a function to each layer object
		{
			std::for_each(_objects.begin(),_objects.end(),f);
		}
		std::vector<ObjectType*> filter(std::function<bool (ObjectType*)> const& f) // Returns ObjectType
		{
			std::vector<ObjectType*> v;
			std::vector<ObjectType*>* pter = &v;
			walk([pter,f](ObjectType *o){if(f) pter->push_back(o);});
			return v;
		}
		template<class In>
		void foreach(In *c,void (In::*action)(ObjectType*)) // Applies a method to every layer element
		{
			walk([c,action](ObjectType *o){(c->*action)(o);});
		}
		template<typename OtherArg>
		void apply(void (ObjectType::*action)(OtherArg),OtherArg *a) // Uses a method from each element
		{
			walk([action,a](ObjectType *o){(o->*action)(a);});
		}
		void apply(void (ObjectType::*action)()) // Uses a method from each object, without argument
		{
			walk([action](ObjectType *o){(o->*action)();});
		}
		void delete_all() // Delete all objects in the layer
		{
			walk([](ObjectType *o){delete o;});
		}
	};
};

#endif