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
		Interval(F2::Interval interval);
		/* Getters */
		/* Setters */
		/* Adders */
		/* Methods */
		/* Static Methods */
	};
}

#endif