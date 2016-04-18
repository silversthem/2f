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
#include "Layer.hpp"

enum Type {Cont,Lay,Single}; // Element types, useful for iteration

namespace F2
{

/* Map (container) class */

	class Map
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
		template<class In,typename Cast>
		void foreach(In *c,void (In::*action)(Cast*)) // Applies a method to every map element
		{
			std::map<std::string,void*>::iterator it      =  _map.begin();
			std::map<std::string,Type>::iterator  it_type = _type.begin();
			for(;it != _map.end();it++)
			{
				switch(it_type->second)
				{
					case Single:
						(c->*action)(static_cast<Cast*>(it->second));
					break;
					case Lay:
						static_cast<Layer<Cast>*>(it->second)->foreach<In>(c,action);
					break;
					case Cont:
						static_cast<Map*>(it->second)->foreach<In,Cast>(c,action);
					break;
				}
				it_type++;
			}
		}
		template<class Cast,typename OtherArg>
		void apply(void (Cast::*action)(OtherArg*),OtherArg *a) // Uses a method from each object
		{
			std::map<std::string,void*>::iterator it      =  _map.begin();
			std::map<std::string,Type>::iterator  it_type = _type.begin();
			for(;it != _map.end();it++)
			{
				switch(it_type->second)
				{
					case Single:
						(static_cast<Cast*>(it->second)->*action)(a);
					break;
					case Lay:
						static_cast<Layer<Cast>*>(it->second)->foreach<OtherArg>(action,a);
					break;
					case Cont:
						static_cast<Map*>(it->second)->foreach<Cast,OtherArg>(action,a);
					break;
				}
				it_type++;
			}
		}
		template<class Cast>
		void apply(void (Cast::*action)()) // Uses a method from each object, without argument
		{
			std::map<std::string,void*>::iterator it      =  _map.begin();
			std::map<std::string,Type>::iterator  it_type = _type.begin();
			for(;it != _map.end();it++)
			{
				switch(it_type->second)
				{
					case Single:
						(static_cast<Cast*>(it->second)->*action)();
					break;
					case Lay:
						static_cast<Layer<Cast>*>(it->second)->apply(action);
					break;
					case Cont:
						static_cast<Map*>(it->second)->apply<Cast>(action);
					break;
				}
				it_type++;
			}
		}
	};
};

#endif