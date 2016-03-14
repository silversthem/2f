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
	typedef Coords Line;

	struct Size // a rectangle object size
	{
		float Width;
		float Height;
	};

	struct Interval_Member // a member of an interval
	{
		float Value;
		bool Excluded;
		/* Operators */
			/* Binary operators */
				/* between intervals */
		friend bool operator==(const Interval_Member& i1,const Interval_Member& i2)
		{
			return (i1.Value == i2.Value);
		}
		friend bool operator!=(const Interval_Member& i1,const Interval_Member& i2)
		{
			return !(i1 == i2);
		}
		friend bool operator<(const Interval_Member& i1,const Interval_Member& i2)
		{
			return (i1.Value < i2.Value);
		}
		friend bool operator>(const Interval_Member& i1,const Interval_Member& i2)
		{
			return i2 < i1;
		}
		friend bool operator<=(const Interval_Member& i1,const Interval_Member& i2)
		{
			return !(i1 > i2);
		}
		friend bool operator>=(const Interval_Member& i1,const Interval_Member& i2)
		{
			return !(i1 < i2);
		}
				/* between interval and float */
		friend bool operator==(const Interval_Member& i,const float& f)
		{
			return (i.Value == f);
		}
		friend bool operator!=(const Interval_Member& i,const float& f)
		{
			return !(i == f);
		}
		friend bool operator<(const Interval_Member& i,const float& f)
		{
			return (i.Value < f);
		}
		friend bool operator>(const Interval_Member& i,const float& f)
		{
			return i.Value > f;
		}
		friend bool operator<=(const Interval_Member& i,const float& f)
		{
			return !(i > f);
		}
		friend bool operator>=(const Interval_Member& i,const float& f)
		{
			return !(i < f);
		}
			/* Assigment */
		Interval_Member& operator=(const float& value) // sets interval value
		{
			Value = value;
			return *this;
		}
		Interval_Member& operator=(const Interval_Member& i) // copy
		{
			Value = i.Value;
			Excluded = i.Excluded;
			return *this;
		}
	};

	struct Interval // an interval
	{
		Interval_Member Start;
		Interval_Member End;
		/* Operators */
		friend bool operator==(const Interval& i1,const Interval& i2)
		{
			if(i1.Start == i2.Start)
			{
				if(i1.End == i2.End)
				{
					return true;
				}
			}
			return false;
		}
		friend bool operator!=(const Interval& i1,const Interval& i2)
		{
			return !(i1 == i2);
		}
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