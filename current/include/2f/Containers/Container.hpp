/*
 * A container is an abstract class to get objects
 * It serves as an interface
 */

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* 2f */
#include "../Objects/Object.hpp"

namespace F2
{
	template<typename ObjectType>
	class Container
	{
		/* Calculations */
		virtual std::vector<ObjectType*> touching(Object *o) = 0;
		// Aligned
		// More...
	};
};

#endif