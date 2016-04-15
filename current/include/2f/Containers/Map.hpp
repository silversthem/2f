/*
 * A map is a collection of layers, maps and individual objects
 * It's used to store objects in a way that they can be modified by groups and accessed easily
 */

#ifndef MAP_HPP
#define MAP_HPP

#include <map>
#include <vector>
#include <string>

enum Type {Vec,Single}; // Element types, useful for iteration

namespace F2
{

/* Map (container) class */

	class Map
	{
	protected:
		std::map<std::string,void*> _map;  // The map
		std::map<std::string,Type > _type; // Map element type
	public:
		Map() // Creating a map
		{
			
		}
		/* Adders */
		template <typename T>
		void add(std::string const& name,T *element) // Adds an element in the map
		{
			_map[name] = element; // Adding it into the map
			_type[name] = Single;
		}
		template <typename T>
		void add_vec(std::string const& name,std::vector<T*> *vec) // Adds a vector in the map
		{
			_map[name] = vec;
			_type[name] = Vec;
		}
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
		Type get_type(std::string const& name)
		{
			if(_type.find(name) != _type.end())
			{
				return _type[name];
			}
			throw "Nothing Found"; // @TODO : Same as get
		}
		/* Deleters */
		// Automatically deletes empty vectors
		// Deletion of map element from the map
		/* Operators */
	};
};

#endif