/*
 * An object is an element in the plan
 * All objects have boundaries and are drawable in the plan
 * This class is abstract for obvious reasons
 * It inherits from ObjectListener for obvious reasons too, I suppose
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics/Rect.hpp>     // For box collision
#include <SFML/System/Vector2.hpp>    // For positions
#include <SFML/Graphics/Drawable.hpp> // To draw the object
/* F2 */
#include "../Listeners/ObjectListener.hpp"

namespace F2
{
	class Frame; // Injection
	class Map;   // Other injection
	template<typename T>
	class Layer; // Still an injection

	class Object : public ObjectListener
	{
	protected:
		Frame* _frame; // Frame of the object
		Map*   _map;   // Map of the object
		Layer<Object>* _l; // Layer of the object
	public:
		Object();  // Creates an object
		~Object(); // Deletes object from the map its contained in
		/* Connections */
		void connect_to_frame(Frame *frame); // Connects object to its frame
		void connect_to_map(Map *map);       // Connects object to its map
		void connect_to_layer(Layer<Object>* l); // Connects object to its layer
		/* Getters */
		Frame* frame(); // Returns the frame the object is in
		virtual const sf::Vector2f& getObjectPosition() = 0; // Gets object position in plan
		virtual       sf::FloatRect getObjectBounds()   = 0; // Gets object boundaries
		virtual const sf::Drawable& getDrawable()       = 0; // Returns what to draw
		/* Collision */
		virtual bool isIn(sf::Vector2f const& point)    = 0; // If a point is in object
		virtual bool touches(Object *o)                 = 0; // If an object touches this one
	};
};

#endif