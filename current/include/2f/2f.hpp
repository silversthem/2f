/* All files */

/* Macros */

#include "macros.hpp"

/* Helper classes : Math */

// Line ~> Defined by two sf::Vector2f and gives things such as length, angle and so on
#include "Math/Line.hpp"
// Path ~> Bunch of lines that an object can follow succesively, useful in pathfinding

/* Frames */

// Plan ~> Where the objects are, also defines boundaries
#include "Frames/Plan.hpp"
// EventMachine ~> Handles events by calling appropriate listeners
#include "Frames/EventMachine.hpp"
// Frame ~> A rendered segment of a Plan, with an event machine and a timer
#include "Frames/Frame.hpp"
// MainFrame ~> Can contain multiple frames, handles multithreading and multiple timers, useful for games with menus and options for example

/* Listeners */

// Listener ~> Virtual methods that'll be called by the event machine when a certains event is happening
#include "Listeners/Listener.hpp"
// ObjectListener ~> A listener applied to objects, with more methods for rendering and such
#include "Listeners/ObjectListener.hpp"

/* Objects */

// Object ~> Default abstract class with all methods objects must have (bounds, position and collision)
#include "Objects/Object.hpp"
// MovingObject ~> Object implements movements
#include "Objects/MovingObject.hpp"
// Projectile ~> Object defined by a movement and easily destroyable by a condition, usually

/* Structures */

// Structure ~> An object composed of tiles, that can generated complex forms such as houses or plateform, useful for pathfinding
// Tile ~> A piece of a structure, Structures can have as many tile combinations as they want, so it's really useful

/* Widgets */

// Text ~> A piece of text can be updated and printed on screen, useful for displaying stuff quick and easy
// Button ~> A clickable rectangle, has 3 states, clicked, hovered and inactive
// Bar ~> Basic widget for progress bars, can also be clicked
// Panel ~> Contains and neatly arranges widgets 

/* Shapes */

// Rectangle ~> A rectangle with collision support
#include "Objects/Shapes/Rectangle.hpp"
// Shape ~> A shape with collision support

/* Sprites */

// Sprite ~> A sprite with texturing and collision support
// Entity ~> Animated sprite, useful to creates good looking characters, or chests and so on...

/* Movements */

// Movement ~> Abstract class to get vector from which to move
// Along ~> A movement along a line
// Toward ~> A movement toward a point, fixed or a pointer
// Offset ~> A movement by an (x,y) offset [All movement can have an angle toward their movement]

/* Forces */

// Constant ~> A constant force being applied, initial speed and max speed can also be defiend
// Fluctuating ~> A force that can change depending on stuff
// Timed ~> A force being controlled by a ticker

/* Time */

// Timer ~> Controls (create/delete) tickers, also defines the "tick"
// Ticker ~> Calls a function/method every X ticks