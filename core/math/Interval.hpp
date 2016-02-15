#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <vector>

#include "../structs.hpp"

namespace Math
{
	class Interval
	{
	protected:
		F2::Interval _interval;
		std::vector<F2::Interval> _unions;
	public:
		Interval(float number); // creates an interval with only one number
		Interval(F2::Interval interval);
		/* Getters */
		F2::Interval getInterval();
		F2::Interval_Member getStart();
		F2::Interval_Member getEnd();
		std::vector<F2::Interval> getUnions();
		F2::Interval getUnion(unsigned int id);
		/* Setters */
		void setStart(F2::Interval_Member member);
		void setEnd(F2::Interval_Member member);
		void setInterval(F2::Interval interval);
		/* Pointers */
		F2::Interval* interval();
		std::vector<F2::Interval>* unions();
		/* Adders */
		void addUnion(F2::Interval interval); // make an union between two intervals
		void addUnion(Math::Interval interval); // same, but with an object
		/* Methods */
		bool isUnique(); // checks if interval contains only one element
		bool isEmpty(); // checks if the interval is empty
		bool contains(float number); // if the interval contains number
		bool contains(F2::Interval interval); // if the interval contains other interval
		bool contains(Math::Interval interval);
		F2::Interval intersect(F2::Interval interval);
		F2::Interval intersect(Math::Interval interval); // takes common numbers in two intervals
		F2::Interval fuse(F2::Interval interval); // fuses two intervals
		Math::Interval fuse(Math::Interval interval);
		/* Static Methods */
		static bool isUnique(F2::Interval interval); // check if interval contains only one element
		static bool isEmpty(F2::Interval interval); // checks if interval is empty
		static bool contains(F2::Interval interval,float number);
		static bool contains(F2::Interval container,F2::Interval test);
		static F2::Interval fuse(F2::Interval i1,F2::Interval i2); // fuses intervals if possible
		static F2::Interval intersect(F2::Interval i1,F2::Interval i2);
	};
}

#endif