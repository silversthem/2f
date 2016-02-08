#ifndef STRUCTS_HPP
#define STRUCTS_HPP

/* Structures used by framework's components */

namespace F2
{
	struct Coords // A point in a plan
	{
		float x;
		float y;
	};

	typedef Coords Point;
	typedef Coords Position;
	typedef Coords Force;
	typedef Coords Speed;
	typedef Coords Direction;
	typedef Coords Plan;

	struct Line // A line equation : y = a*x + b
	{
		float a;
		float b;
	};

	struct Size // a rectangle object size
	{
		float Width;
		float Height;
	};

	struct Interval_Member // a member of an interval
	{
		float Value;
		float Excluded;
	};

	struct Interval // an interval
	{
		Interval_Member Start;
		Interval_Member End;
	};

	namespace Oriented
	{
		struct Segment // an oriented segment is defined as an angle and a length
		{
			float Angle;
			float Length;
		};

		typedef Segment Force;
		typedef Segment Speed;
		typedef Segment Direction;
	}
}

#endif