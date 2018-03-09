#include "../../../include/2f/Containers/Map.hpp"

F2::Map::Map()
{
	
}

F2::Map::~Map()
{
	std::map<std::string,void*>::iterator it = _map.begin();
	for(;it != _map.end();it++)
	{
		static_cast<F2::FrameBinder<Map*,void*>*>(it->second)->unbind();
	}
}

/* Getters */

F2::Type F2::Map::get_type(std::string const& name)
{
	if(_type.find(name) != _type.end())
	{
		return _type[name];
	}
	throw "Nothing Found"; // @TODO : Same as get
}

std::map<std::string,void*>* F2::Map::map()
{
	return &_map;
}

/* Deleters */

void F2::Map::del_map(Map *m) // Deletes a map
{
	del(m);
}