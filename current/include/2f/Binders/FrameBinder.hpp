/*
 * FrameBinder is an abstract class used to connect/disconnect objects or containers to Frames and their containers
 * Used by maps, layers and objects.
 * This class is very important, because it allows me to do one injection once and for all, and now I can worry about other stuff
 */

#ifndef FRAMEBINDER_HPP
#define FRAMEBINDER_HPP

namespace F2
{
	class Frame; // Injection
	class Map;   // Other Injection
	template<typename ObjectType,typename Parent>
	class Layer; // Still an injection

	class FrameBinder
	{
	protected:
		Frame     *_frame; // Object frame
		enum {ToMap,ToLayer,None} _bind; // To know which binding to use
		union // Possibilities for binding
		{
			Map*    _map;
			void* _layer;
		};

	public:
		FrameBinder(); // Creating a frame binder
		void connect(Frame *f); // Connects to frame
		void disconnect();      // Disconnects from frame
		/* Binding */
		void bind_to_map(Map *m); // Connects to map
		void bind_to_layer(void* l); // Connects to layer
		/* Unbinding */
		void delete_from_bound(); // Deletes self from connected map/layer
		void unbind(); // Resets bound
		/* Getters */
		Map* map();
		Frame* frame();
		template<typename T>
		Layer<T,Map*>* layer()
		{
			// @TODO : check _bind
			return static_cast<Layer<T,Map*>*>(_layer);
		}
	};
};

#endif