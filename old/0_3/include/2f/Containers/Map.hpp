/*
 * A map is a collection of layers, maps and individual objects
 * It's used to store objects in a way that they can be modified by groups and accessed easily
 */

#ifndef MAP_HPP
#define MAP_HPP

#include <map>
#include <string>
/* 2f */
#include "Layer.hpp"

namespace F2
{
	enum Type {Cont,Lay,Single}; // Element types, useful for iteration

	class Map : public FrameBinder<Map*,void*>
	{
	protected:
		std::map<std::string,void*> _map; // The map
		std::map<std::string,Type> _type; // Map element type
	public:
		Map(); // Creating a map
		~Map(); // Deleting a map
		/* Adders */
		template <class T>
		void add(std::string const& name,T *element) // Adds an element in the map
		{
			element->connect(frame());
			element->bind_to_map(this);
			_map[name] = element; // Adding it into the map
			_type[name] = Single;
		}
		template <class T>
		void add_layer(std::string const& name,Layer<T> *l) // Adds a layer in the map
		{
			l->connect(frame());
			l->bind_to_map(this);
			_map[name] = l;
			_type[name] = Lay;
		}
		// Adds a map in the map
		/* Getters */
		template <class T>
		T* get(std::string const& name) // Gets an element in the map
		{
			if(_map.find(name) != _map.end())
			{
				return static_cast<T*>(_map[name]);
			}
			throw "Nothing Found"; // @TODO : Change for an exception
		}
		template <class T>
		T get_layer(std::string const& name) // Returns a layer in the map
		{
			return get<Layer<T>*>(name);
		}
		// Map
		Type get_type(std::string const& name); // Returns an element type : layer/map or single object
		std::map<std::string,void*>*     map(); // Returns the std::map container
		/* Deleters */
		void del(void* element) // Deletes an element
		{
			std::map<std::string,void*>::iterator it = _map.begin();
			for(;it != _map.end();it++)
			{
				if(element == it->second)
				{
					_map.erase(it);
					break; // Element was deleted, no need to go further
				}
			}
		}
		template<class T>
		void del_layer(Layer<T,Map*> *l) // Deletes a layer
		{
			del(l);
		}
		void del_map(Map *m); // Deletes a map
		/* Container methods */
		template <class Cast> // applies a function through the map
		void walk(std::function<void (Cast*)> const& f,bool const& toObjects = true,bool const& toLayers = true,bool const& toMaps = true)
		{
			std::map<std::string,void*>::iterator it      =  _map.begin();
			std::map<std::string,Type>::iterator  it_type = _type.begin();
			for(;it != _map.end();it++)
			{
				switch(it_type->second)
				{
					case Single:
						if(toObjects)
						{
							f(static_cast<Cast*>(it->second));
						}
					break;
					case Lay:
						if(toLayers)
						{
							static_cast<Layer<Cast>*>(it->second)->walk(f);
						}
					break;
					case Cont:
						if(toLayers)
						{
							static_cast<Map*>(it->second)->walk<Cast>(f,toObjects,toLayers,toMaps);
						}
					break;
				}
				it_type++;
			}
		}
		// @TODO : Filters a map
		template<class In,class Cast>
		void foreach(In *c,void (In::*action)(Cast*)) // Applies a method to every map element
		{
			walk<Cast>([c,action](Cast* object){(c->*action)(object);});
		}
		template<class Cast,class OtherArg>
		void apply(void (Cast::*action)(OtherArg*),OtherArg *a) // Uses a method from each object
		{
			walk<Cast>([action,a](Cast* object){(object->*action)(a);});
		}
		template<class Cast>
		void apply(void (Cast::*action)()) // Uses a method from each object, without argument
		{
			walk<Cast>([action](Cast* object){(object->*action)();});
		}
		// @TODO : Apply to objects only
		template <class Cast>
		void apply_to_layers(void (Layer<Cast>::*action)()) // Applies a function to layers only
		{
			walk<Cast>([action](Layer<Cast>* layer){(layer->*action)();});
		}
		// @TODO : Apply to map only
	};
};

#endif