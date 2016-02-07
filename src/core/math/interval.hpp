#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <vector>

class Interval
{
	protected:
		float _start;
		float _end;
		std::vector<Interval> _unions;
	public:
		Interval(float start,float end);
		/* Getters */
		float getStart();
		float getEnd();
		std::vector<Interval> getUnions();
		/* Setters */
		void setInterval(float start,float end);
		void setUnions(std::vector<Interval> &unions);
		/* Adders */
		void addUnion(Interval interval);
		/* Operators */
		Interval operator&&(Interval &interval); // alias of intersects
		Interval operator||(Interval &interval); // alias of unite
		/* Methods */
		static Interval interval(float start,float end);
		static Interval intersectize(Interval i1,Interval i2);
		static Interval unionize();
		bool contains(float number,bool closedInterval = true);
		bool isEmpty();
		Interval unite(Interval &interval);
		Interval intersects(Interval &interval);
};

#endif
