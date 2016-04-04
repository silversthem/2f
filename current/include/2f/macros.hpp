/*
 * Useful macros
 */

#ifndef MACROS_HPP
#define MACROS_HPP

/* Organisation macros */

#define USE(x) class x; // Use a class
#define VECTOR_OF(x) std::vector<x*> // Vector of pointers to stuff

/* Math macros */

#define PI 3.14159265 // Pi
#define TAU PI*2 // Tau

#define RAD(x) x*(PI/180) // Converts degrees in radians
#define DEG(x) x*(180/PI) // Converts Radians in degrees

#define ABS_DEG(x) x%360 // returns a value between 0 and 360 degrees
#define ABS_RAD(x) x%TAU // returns a value between 0 and 2*pi radians

#define OPPOSITE_DEG(x) (x+180)%360 // returns the opposite direction for an angle in degrees
#define OPPOSITE_RAD(x) (x+PI)%TAU // returns the opposite direction for an angle in radians

#endif
