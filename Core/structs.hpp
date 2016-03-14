#ifndef STRUCTS_HPP_INCLUDED
#define STRUCTS_HPP_INCLUDED

#include <cmath>

#define PI 3.14159265
#define TAU PI*2

#define RAD(x) x*(PI/180) // Converts degrees in radians
#define DEG(x) x*(180/PI) // Converts Radians in degrees

#define ABS_DEG(x) x%360 // returns a value between 0 and 360 degrees
#define ABS_RAD(x) x%TAU // returns a value between 0 and 2*pi radians

#define OPPOSITE_DEG(x) (x+180)%360 // returns the opposite direction for an angle in degrees
#define OPPOSITE_RAD(x) (x+PI)%TAU // returns the opposite direction for an angle in radians

/* Structures */

struct Line // A line
{
	float angle; // Angle, in degrees
	float length; // line length
	static const int INFINITE = -1; // The line never stops
};

#endif