/*
 * A map is a collection of layers, maps and individual objects
 * It's used to store objects in a way that they can be modified by groups and accessed easily
 */

#ifndef MAP_HPP
#define MAP_HPP

#include <map>
#include <vector>
#include <string>
/* 2f */
#include "Container.hpp"
#include "Layer.hpp"

enum Type {Container,Lay,Single}; // Element types, useful for iteration

namespace F2
{

/* Map (container) class */

	class Map // : public Container @TODO
	{
	protected:
		Map* _parent; // If the map has a parent
		std::map<std::string,void*> _map; // The map
		std::map<std::string,Type> _type; // Map element type
	public:
		Map() // Creating a map
		{
			_parent = 0;
		}
		~Map() // Deleting a map
		{
			if(_parent != 0)
			{
				// Deleting it from parent
			}
		}
		/* Adders */
		template <typename T>
		void add(std::string const& name,T *element) // Adds an element in the map
		{
			element->connect_to_map(this);
			_map[name] = element; // Adding it into the map
			_type[name] = Single;
		}
		template <typename T>
		void add_layer(std::string const& name,Layer<T> *l) // Adds a layer in the map
		{
			l->connect_to_map(this);
			_map[name] = l;
			_type[name] = Lay;
		}
		// Adds a map in the map
		/* Getters */
		template <typename T>
		T get(std::string const& name) // Gets an element in the map
		{
			if(_map.find(name) != _map.end())
			{
				return *static_cast<T*>(_map[name]);
			}
			throw "Nothing Found"; // @TODO : Change for an exception
		}
		template <typename T>
		T get_layer(std::string const& name) // Returns a layer in the map
		{
			return get<Layer<T>*>(name);
		}
		// Map
		Type get_type(std::string const& name)
		{
			if(_type.find(name) != _type.end())
			{
				return _type[name];
			}
			throw "Nothing Found"; // @TODO : Same as get
		}
		std::map<std::string,void*>* map() // Returns the map
		{
			return &_map;
		}
		/* Deleters */
		template<typename T>
		void del(T* element) // Deletes an element
		{
			// ...
		}
		template<typename T>
		void del_layer(Layer<T> *l) // Deletes a layer
		{
			// ...
		}
		/* Methods */
		void connect(Map* m) // Connecting the map to its parent
		{
			_parent = m;
		}
		/* Container methods */
		// ...
	};
};

#endif