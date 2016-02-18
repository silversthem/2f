#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <cmath>

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

	float radToDeg(float rad)
	{
		return (360/6.28)*rad;
	}

	float DegToRad(float deg)
	{
		return (6.28/360)*deg;
	}

	Oriented::Segment LineToSegment(Line line)
	{
		Oriented::Segment s;
		if(line.x == 0) // vertical line
		{
			if(line.y < 0) // downwards
			{
				s.Angle = 90;
				s.Length = -1*line.y;
			}
			else if(line.y > 0) // upwards
			{
				s.Angle = 270;
				s.Length = line.y;
			}
			else // point
			{
				s.Angle = 0;
				s.Length = 0;
			}
		}
		else
		{
			s.Angle = radToDeg(std::tan(line.y/line.x));
			s.Length = std::sqrt(line.y*line.y + line.x*line.x);
		}
		return s;
	}

	Line SegmentToLine(Oriented::Segment segment)
	{
		Line l;
		if(segment.Angle == 90) // vertical upward line
		{
			l.x = 0;
			l.y = -1*segment.Length;
		}
		if(segment.Angle == 270) // vertical downward line
		{
			l.x = 0;
			l.y = segment.Length;
		}
		else // random line
		{
			l.x = std::cos(segment.Angle) * segment.Length;
			l.y = std::sin(segment.Angle) * segment.Length;
		}
		return l;
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