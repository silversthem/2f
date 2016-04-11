/*
 * A ListenerContainer is a container created especially for listeners
 * It can automatically handle connection/deconnection and handles deletion by default
 * (When a listener is being deleted, it excludes it automatically)
 */

#ifndef LISTENERCONTAINER_HPP
#define LISTENERCONTAINER_HPP

#include "Container.hpp"
#include "../Listeners/Listener.hpp"

#define Parent Container<Vector,Iter,ListenerClass,User> // Container class
#define LCONTAINER(x,y) ListenerContainer<std::vector<x*>,std::vector<x*>::iterator,x,y> 

namespace F2
{
	template<typename Vector,class Iter,typename ListenerClass,typename User = int>
	class ListenerContainer : public Container<Vector,Iter,ListenerClass,User>
	{
	protected:
		bool _connection; // Should we connect and disconnect the listeners
	public:
		ListenerContainer(bool const& connection = true) // Creates an listenerContainer
		{
			_connection = connection;
		}
		virtual void add(ListenerClass *l) // Adds a listener in the container
		{
			if(_connection)
			{
				l->connect();
			}
			Parent::_vec.push_back(l);
		}
		/* Methods overriden */
		bool shouldBeDeleted(ListenerClass* i)
		{
			return i->isDeleting();
		}
		void onDeletion(ListenerClass* i)
		{
			if(_connection)
			{
				i->disconnect();
			}
		}
	};
};

#endif