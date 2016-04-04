#include <iostream>

#include "2f.hpp"

/* Interval test */

int main()
{
	Math::Interval i1(F2::interval(1,10)); // [1,10]
	Math::Interval i2(F2::interval(2,3)); // [2,3]
	Math::Interval i3(F2::interval(2,14)); // [6,14]

	i3.addUnion(F2::interval(0,4)); // union [0,4]u[2,14]

	Math::Interval intersection = i1.intersect(i2); // intersection [1,10]n[2,3]

	if(!intersection.isEmpty())
	{
		std::cout << "i1 et i2 on des nombres en commun" << std::endl;
		std::cout << "L'intersection donne l'intervalle : " << "["
		<< intersection.getMinimum().Value << "," <<
		intersection.getMaximum().Value << "]" << std::endl;
	}
	if(i3.isContinous()) // if interval [0,4]u[2,14] can be written as one
	{
		std::cout << "i3 est continue entre : " << i3.getMinimum().Value
		<< " et " << i3.getMaximum().Value << std::endl;
	}
	return 0;
}