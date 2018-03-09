/*
 * A movement is a programmed deplacement of a certain offset
 * Calculation parameter for offset include, but are not limited to :
 * Object and other objects position, Tickers, Time, Speed and Bounds
 */

#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

namespace F2
{
	namespace Movement
	{
		enum OnActive{Pressing,Releasing,Always}; // When the movement should be actived

		class Movement
		{
		protected:
			const sf::Vector2f* _pos; // Movement position
			float _speed;             // Movement speed
			/* Movement control */
			bool _enabled; // If the movement is actived
			bool  _active; // If the movement should be applied this iteration ~> gets overidden by "enable"
		public:
			Movement(sf::Vector2f const& _pos); // Creates a movement
			/* Getters */
			sf::Vector2f getMovement(); // Gets offset by which to mouse
			bool isActive();            // Is the movement active
			bool isEnabled();           // If the movement is enabled
			/* Setters */
			void setActive(OnActive const& a); // Sets when the movement
			void setSpeed(float const& speed); // Sets movement speed
			/* Movement control */
			void press();   //
			void release(); //
			void enable();  //
			void disable(); //
		};
	};
};

#endif