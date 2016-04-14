/*
 * A map is a collection of layers, maps and individual objects
 * It's used to store objects in a way that they can be modified by groups and accessed easily
 */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <stdlib.h>
#include <map>

namespace F2
{

/* Map (container) class */

	class Map
	{
	protected:
		std::map<std::string,void*> _map; // The map
	public:
		Map() // Creating a map
		{
			
		}
		template <typename T>
		void add(std::string const& name,T *element) // Adds an element in the map
		{
			_map[name] = element; // Adding it into the map
		}
		template <typename T>
		T get(std::string const& name) // Gets an element in the map
		{
			if(_map.find(name) != _map.end())
			{
				return *static_cast<T*>(_map[name]);
			}
			throw "Nothing Found";
		}
		/* Operators */
	};
};

#endif