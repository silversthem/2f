#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

#include "object.hpp"
#include "../math/path.hpp"

#include <vector>

class Structure : Object
{
	protected:
		std::vector<Position> _Points; // Edges of the structure
		std::vector<Position> _EntryPoints; // Ways to go inside
	public:
		Structure();
		/* methods */
		Path LinePathfind(const Object &start,const Object &end);
		Path pathfind(const Object &start,const Object &end,std::vector<*Structure> obstacles);
		bool collides(const Object &tester,const Line &line); // tests if the object touches the structure
		bool collides(const Object &tester,const Path &path); // tests if the path tries to go through the structure
		void addPoints(const Position &pos);
		void addEntry(const Position &entry);
};

#endif