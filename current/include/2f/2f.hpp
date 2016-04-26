/* All files */

/* Macros */

#include "macros.hpp"

/* Helper classes : Math */

// Line ~> Defined by two sf::Vector2f and gives things such as length, angle and so on
#include "Math/Line.hpp"
// Path ~> Bunch of lines that an object can follow succesively, useful in pathfinding

/* Helper classes : Binders */

// FrameBinder ~> Binds objects, and containers to their frame and eventual parent container
#include "Binders/FrameBinder.hpp"
// EventBinder ~> Binds actions to events
#include "Binders/EventBinder.hpp"
// ActionBinder ~> Action executed when called by the EventBinder
#include "Binders/ActionBinder.hpp"
// ObjectBinder ~> Implementation of ActionBinder where the action is a lambda function, which can be filtered using another lambda
#include "Binders/ObjectBinder.hpp"
// TimeBinder   ~> Binders responding to certain tick amounts

/* Helper classes : Models */

// LayerManager ~> Handles objects in layers
// MapManager   ~> Handles objects and layers in map
// FrameManager ~> Handles map and others in frame
// SpriteManager ~> Handles textures for sprites
// EntityManager ~> Handles textures & animations for entities

/* Helper classes : Containers */

// Map ~> Collections of layers, objects and other maps
#include "Containers/Map.hpp"
// Layer ~> Collection of objects
#include "Containers/Layer.hpp"

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
#include "Objects/Projectile.hpp"

/* Sprites */

// Tile ~> A textured rectangle
#include "Objects/Sprites/Tile.hpp" 
// Sprite ~> A tile with multiple display textures
#include "Objects/Sprites/Sprite.hpp"
// Entity ~> A sprite whose multiple display textures can be regrouped to be animated
#include "Objects/Sprites/Entity.hpp"

/* Structures */

// Structure ~> An object composed of tiles, that can be pathfinded through
// Building  ~> A structure with entries and exits

/* Widgets */

// Text ~> A piece of text can be updated and printed on screen, useful for displaying stuff quick and easy
// Button ~> A clickable rectangle, has 3 states, clicked, hovered and inactive
// Bar ~> Basic widget for progress bars, can also be clicked
// Panel ~> Contains and neatly arranges widgets 

/* Shapes */

// Rectangle ~> A rectangle with collision support
#include "Objects/Shapes/Rectangle.hpp"
// Shape ~> A shape with collision support
// Circle ~> A circle with collision support
#include "Objects/Shapes/Circle.hpp"

/* Movements */

// Movement ~> Abstract class to get vector from which to move
#include "Movements/Movement.hpp"
// Along ~> A movement along a line
#include "Movements/Along.hpp"
// Toward ~> A movement toward a point, fixed or a pointer
#include "Movements/Toward.hpp"
// Offset ~> A movement by an (x,y) offset [All movement can have an angle toward their movement]
#include "Movements/Offset.hpp"
// DragDrop ~> A drag & drop movement

/* Forces */

// Constant ~> A constant force being applied, initial speed and max speed can also be defined
// Lambda ~> A force that takes a method/function as a parameter and uses it to calculate the movement

/* Time */

// Timer ~> Controls time and ticks on objects
#include "Time/Timer.hpp"