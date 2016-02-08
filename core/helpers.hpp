#ifndef HELPERS_HPP
#define HELPERS_HPP

/* Functions to create structures faster */

#include "structs.hpp"

using namespace F2;

Point coords(float x,float y)
{
	Point p;
	p.x = x;
	p.y = y;
	return p;
}

Size size(float w,float h)
{
	Size s;
	s.Width = w;
	s.Height = h;
	return s;
}

Oriented::Segment segment(float angle,float length)
{
	Oriented::Segment s;
	s.Angle = angle;
	s.Length = length;
	return s;
}

Interval interval(float start,float end,bool startEx = false,bool endEx = false)
{
	Interval I;
	Interval_Member Istart;
	Istart.Value = start;
	Istart.Excluded = startEx;
	I.Start = Istart;
	Interval_Member Iend;
	Iend.Value = end;
	Iend.Excluded = endEx;
	I.End = Iend;
	return I;
}

#endif