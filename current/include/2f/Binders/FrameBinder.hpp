/*
 * FrameBinder is an abstract class used to connect/disconnect objects or containers to Frames and their containers
 * Used by maps, layers and objects.
 * This class is very important, because it allows me to do one injection once and for all, and now I can worry about other stuff
 */

#ifndef FRAMEBINDER_HPP
#define FRAMEBINDER_HPP

#include <iostream>

namespace F2
{
	class Frame; // Injection
	class Map;   // Other Injection
	template<typename ObjectType,typename Parent>
	class Layer; // Still an injection

	template<typename MapClass = Map*,typename LayerClass = void*>
	class FrameBinder
	{
	protected:
		Frame     *_frame; // Object frame
		enum {ToMap,ToLayer,None} _bind; // To know which binding to use
		union // Possibilities for binding
		{
			MapClass     _map;
			LayerClass _layer;
		};

	public:
		FrameBinder() // Creating a frame binder
		{
			_bind = F2::FrameBinder<Map*,void*>::None;
			_frame = 0;
		}
		void connect(Frame *f) // Connects to frame
		{
			_frame = f;
		}
		void disconnect() // Disconnects from frame
		{
			_frame = 0;
		}
		/* Binding */
		void bind_to_map(Map *m) // Connects to map
		{
			_bind = F2::FrameBinder<Map*,void*>::ToMap;
			_map = m;
		}
		void bind_to_layer(void* l) // Connects to layer
		{
			_bind = F2::FrameBinder<Map*,void*>::ToLayer;
			_layer = l;
		}
		/* Unbinding */
		template<typename T = FrameBinder>
		void delete_from_bound(void *address) // Deletes self from connected map/layer
		{
			switch(_bind)
			{
				case F2::FrameBinder<Map*,void*>::ToLayer:
					layer<T>()->del(static_cast<T*>(address));
				break;
				case F2::FrameBinder<Map*,void*>::ToMap:
					map()->del(address);
				break;
				default:
					// ...
				break;
			}
			_bind = F2::FrameBinder<Map*,void*>::None;
		}
		void unbind() // Resets bound
		{
			_bind = F2::FrameBinder<Map*,void*>::None;
		}
		/* Getters */
		Map* map()
		{
			if(_bind != F2::FrameBinder<Map*,void*>::ToMap)
			{
				throw 1; // @TODO : Exception
			}
			return _map;
		}
		Frame* frame()
		{
			if(_frame == 0)
			{
				throw 1; // @TODO : Exception
			}
			return _frame;
		}
		template<typename T>
		Layer<T,Map*>* layer()
		{
			if(_bind != F2::FrameBinder<Map*,void*>::ToLayer)
			{
				throw 1; // @TODO : Exception
			}
			return static_cast<Layer<T,Map*>*>(_layer);
		}
	};
};

#endif