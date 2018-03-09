/*
 * A projectile is an bject defined by a movement and easily destroyable
 * Bullets, balls, arrows and others are usually projectiles
 */

#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

/* 2f */
#include "../Movements/Movement.hpp"

namespace F2
{
	template <typename DrawableObject>
	class Projectile
	{
	protected:
		DrawableObject Shape; // The shape
		Movement::Movement Trajectory;  // The projectile trajectory
	public:
		Projectile(); // Creates a projectile
		/* Methods */
		
	};
};

#endif