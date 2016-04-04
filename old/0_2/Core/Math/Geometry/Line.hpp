#ifndef LINE_HPP
#define LINE_HPP

#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <cmath>

#define PI 3.14159265
#define TAU PI*2

#define RAD(x) x*(PI/180) // Converts degrees in radians
#define DEG(x) x*(180/PI) // Converts Radians in degrees

#define ABS_DEG(x) x%360 // returns a value between 0 and 360 degrees
#define ABS_RAD(x) x%TAU // returns a value between 0 and 2*pi radians

#define OPPOSITE_DEG(x) (x+180)%360 // returns the opposite direction for an angle in degrees
#define OPPOSITE_RAD(x) (x+PI)%TAU // returns the opposite direction for an angle in radians

/* A line */

class Line
{
protected:
	float _length; // Line length
	bool _isInfinite; // If the line is infinite
	float _angle; // Line angle
	const sf::Vector2f* _point1; // If line is defined by two stored point, this is the first point
	const sf::Vector2f* _point2; // This is the second point (the line is said to be absolute)
	void calculateLine(); // if line is absolute, calculating it
	void absolute(); // Handles the case where the line is absolute
public:
	Line(); // Creates a line
	Line(float const& length,float const& angle = 0); // Creates a line with a length and angle
	Line(sf::Vector2f const& point1,sf::Vector2f const& point2,bool store1 = false,bool store2 = false); // Creates a line from two points
	/* Getters */
	float angle(); // Line angle
	float length(); // Line length
	/* Setters */
	void setLine(float const& length,float const& angle); // Defines a line
	void setAngle(float const& angle); // Sets line angle
	void setLength(float const& length); // Sets line length
	void setInfinite(bool const& infinite); // If the line is infinite
	/* Testers */
	bool isAligned(sf::Vector2f const& point); // If a point is aligned with a line
	bool intersect(Line const& line); // If two lines cross each other
	bool overlap(Line const& line); // If lines are overlapping
	bool isVertical(); // If the line is vertical
	bool isAbsolute(); // If the line is defined by at least one point in plan, and not just by length/angle
	/* Calculations */
	float coefficient(); // A line is y = a*x+b in plan, this returns the a
	void rotate(float const& angle); // Rotates the ligne
	sf::Vector2f applyLine(float const& number); // Returns a point on the line
	sf::Vector2f intersection(Line const& line); // Returns intersection between lines, if there's one
	/* Static */
	static float getAngle(sf::Vector2f const& point1,sf::Vector2f const& point2); // Returns oriented degree angle
	static float getDistance(sf::Vector2f const& point1,sf::Vector2f const& point2); // Returns distance between two points
	/* Absolute (with pointers to points defined) methods */
	const sf::Vector2f& getFirstPoint() const; // Returns first point
	const sf::Vector2f& getSecondPoint() const; // Returns second point
	void setPoints(sf::Vector2f const& point,sf::Vector2f const& point2); // Sets points
	/* Operators */
	void copy(Line& line); // Copies line and angle from other line, without caring about stored points or whatever
};

#endif