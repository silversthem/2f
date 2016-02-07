#ifndef STRUCTS_HPP
#define STRUCTS_HPP

struct Line
{
	float a;
	float b;
};

struct Coords
{
	float x = 0;
	float y = 0;
};

typedef Coords Position;
typedef Coords Force;
typedef Coords Speed;

struct Size
{
	int w = 0;
	int h = 0;
};

#endif