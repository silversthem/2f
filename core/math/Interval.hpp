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
		Interval();
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
		bool isEmpty(); // checks if the interval is empty
		bool contains(float number); // if the interval contains number
		Math::Interval intersect(Math::Interval); // takes common numbers in two intervals
		/* Static Methods */
		static bool contains(F2::Interval interval,float number);
		static F2::Interval intersect(F2::Interval i1,F2::Interval i2);
		static F2::Interval unionize(F2::Interval i1,F2::Interval i2);
		static Math::Interval create(float start,float end,bool startEx = false,bool endEx = false)
		{
			Interval I;
			I.interval()->Start.Value = start;
			I.interval()->Start.Excluded = startEx;
			I.interval()->End.Value = end;
			I.interval()->End.Excluded = endEx;
			return I;
		}
	};
}

#endif