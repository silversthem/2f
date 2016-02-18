#ifndef HELPERS_HPP
#define HELPERS_HPP

/* Functions to create structures faster */

#include "structs.hpp"

using namespace F2;

namespace F2
{
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

	Oriented::Segment LineToSegment(Line line)
	{
		// ...
	}

	Line SegmentToLine(Oriented::Segment segment)
	{
		// ...
	}

	Interval_Member interval_member(float value,bool excluded = false)
	{
		Interval_Member m;
		m.Value = value;
		m.Excluded = excluded;
		return m;
	}

	Interval interval(float start,float end,bool startEx = false,bool endEx = false)
	{
		Interval I;
		I.Start = interval_member(start,startEx);
		I.End = interval_member(end,endEx);
		return I;
	}
}

#endif