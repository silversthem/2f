/*
 * A plan is the object container
 * Defined by bounds
 * Contained structures, objects, projectiles and widgets
 * Can handle everything collision related, but also aligment, distance and else
 * Contains template methods to use on your own collections
 * Also contains the pathfinding algorithm
 */

#ifndef PLAN_HPP
#define PLAN_HPP

#include <vector> // Object and others container
/* 2f */
#include "../macros.hpp"
#include "../Math/Line.hpp"
#include "../Objects/Object.hpp"

namespace F2
{
	class Plan
	{
	protected:
		sf::FloatRect _bounds; // Bounds of the plan
		VECTOR_OF(F2::Object) _objects; // Objects in plan
		/* Template calculations */
		template<typename Ob,class Iter> VECTOR_OF(Ob) touching(Object *p,Iter const& begin,Iter const& end)
		{
			VECTOR_OF(Ob) objects;
			Iter b = begin;
			for(;b != end;b++)
			{
				if(p->touches(*b) && p != *b && !(*b)->isDeleting())
				{
					objects.push_back(*b);
				}
			}
			return objects;
		}
	public:
		/* Constructors */
		Plan();
		Plan(float width,float height); // Creates a bounded plan
		/* Adders */
		virtual void addObject(Object *o); // Adds an object in the plan
		/* Setters */
		void setBounds(float width,float height); // Sets bounds of plan
		/* Getters */
		VECTOR_OF(F2::Object) getInBounds(sf::FloatRect const& rect,F2::Object *self = NULL); // Get objects in a certain rectangle
	};
};

#endif