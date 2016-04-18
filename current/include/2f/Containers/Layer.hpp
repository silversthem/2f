/*
 * A layer is a collection of objects stored as their real type (no downcasting)
 * Layers are contained in map
 * Layers can use collision and detection methods with other objects
 */

#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>

namespace F2
{
	class Map; // Injection

	template<typename ObjectType>
	class Layer
	{
	protected:
		std::vector<ObjectType*> _objects; // Objects of the layer
		Map *_map; // Layer map
	public:
		Layer()  // Creates a layer
		{
			_map != 0;
		}
		~Layer(); // Removes it from the map
		/* Methods */
		void add(ObjectType *o) // Adds an object in the layer
		{
			o->connect_to_layer(this);
			_objects.push_back(o);
		}
		void connect(Map *m) // Connects layer to its map
		{
			_map = m;
		}
		std::vector<ObjectType*>* vector() // Returns the vector
		{
			return &_objects;
		}
		void del(ObjectType *o) // Deletes an element
		{
			
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