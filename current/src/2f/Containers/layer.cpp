#include "../../../include/2f/Containers/Layer.hpp"
#include "../../../include/2f/Containers/Map.hpp"

template<typename T>
F2::Layer<T>::~Layer()
{
	_map->del_layer(this);
}