#ifndef INTERVAL_HPP_INCLUDED
#define INTERVAL_HPP_INCLUDED

/* Represents a mathematical interval between two intervals */

#include <vector>

class Interval; // declaration to avoid conflits

struct interval
{
	float start;
	float end;
	/* Comparative Operators */
	inline bool operator>(interval const& i); // if start of one is superior
	inline bool operator<(interval const& i); // if end of one is inferior
	inline bool operator>=(interval& i); // if start is superior but interval is continuous
	inline bool operator<=(interval& i); // if end is inferior but interval is continuous
	inline bool operator==(interval const& i); // if left one contains right one
	inline bool operator!=(interval const& i); // if left one doesn't contains right one
	inline bool operator<<(float const& number); // if number is contained in interval
	inline interval operator&&(interval const& i); // get intersection
	inline Interval operator||(interval const& i); // get union
};

class Interval
{
protected:
	std::vector<interval> _intervals; // unions of intervals in object
	/* interval structure methods */
	interval create(float const& start,float const& end); // creates an interval structure
	
public:
	Interval(float const& start,float const& end); // creates an interval
	/* getters */
	/* setters */
	/* methods */
};

#endif