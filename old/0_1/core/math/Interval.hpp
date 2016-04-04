#ifndef INTERVAL_HPP
#define INTERVAL_HPP

/* An mathematic interval between numbers, also support unions */

#include <vector>

#include "../structs.hpp"

typedef std::vector<F2::Interval> Intervals;

namespace Math
{
	class Interval
	{
	protected:
		F2::Interval _interval; // Intervals
		Intervals _unions; // Unions
	public:
		Interval(); // Creates an empty interval
		Interval(float number); // creates an interval with only one number
		Interval(F2::Interval interval); // creates an interval object from an interval structure
		/* Getters */
		F2::Interval getInterval(); // returns the interval
		F2::Interval getUnion(unsigned int id); // get a specific union
		F2::Interval_Member getStart(); // get the first interval member
		F2::Interval_Member getEnd(); // get the end
		F2::Interval_Member getMinimum(); // get smallest number across all unions
		F2::Interval_Member getMaximum(); // same but with maximum
		Intervals getUnions(); // returns the vector containing unions
		/* Setters */
		void setStart(F2::Interval_Member member); // sets interval start
		void setEnd(F2::Interval_Member member); // sets interval end
		void setInterval(F2::Interval interval); // sets the interval
		void setUnions(std::vector<F2::Interval> unions); // sets the unions vector
		/* Pointers */
		F2::Interval* interval(); // returns a pointer to the interval structure
		Intervals* unions(); // returns a pointer to the unions vector
		/* Adders */
		void addUnion(F2::Interval interval); // make an union between two intervals
		void addUnion(Math::Interval interval); // same, but with an object
		/* Methods */
		void clear(); // makes the interval empty
		bool isUnique(); // checks if interval contains only one number
		bool isEmpty(); // checks if the interval is empty
		bool isContinous(); // checks if the intervals are one
		bool contains(float number); // if the interval contains number
		bool contains(F2::Interval interval); // if the interval contains other interval
		bool contains(Math::Interval interval); // same, but with an interval object
		Math::Interval intersect(F2::Interval interval); // takes common numbers in two intervals
		Math::Interval intersect(Math::Interval interval); // same, but with interval object
		void fuse(); // fuses unions to shorten length
		/* Static Methods */
		static bool isUnique(F2::Interval interval); // check if interval contains only one element
		static bool isEmpty(F2::Interval interval); // checks if interval is empty
		static bool isContinous(F2::Interval i1,F2::Interval i2); // if two interval can fuse into 1
		static bool contains(F2::Interval interval,float number); // if interval contains number
		static bool contains(F2::Interval container,F2::Interval test); // if interval contains other
		static Math::Interval fuse(F2::Interval i1,F2::Interval i2); // fuses intervals if possible
		static F2::Interval intersect(F2::Interval i1,F2::Interval i2); // Intersects two intervals
	};
}
#endif