/*
 * A container is an array of pointers that handle deleting on the fly
 * When you have multiple vectors of pointers containing a pointer to the same object, this comes in handy
 * Note : this class is abstract, you have to fill in your own deletion criteria for the contained
 * Also : The function to execute in deletion and in "normal" are to be filled by you
 * Also : This class can be instanced via a macro, because normally it's really bad and ugly
 */

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#define CONTAINER(x,y) Container<std::vector<x*>,std::vector<x*>::iterator,x,y> // Easily creates a container

namespace F2
{
	template<typename Vector,class Iter,typename Contained,typename User>
	class Container
	{
	protected:
		Vector _vec; // Vector of contained stuff
		Iter it;     // Iterator to go through that stuff
		User* _user; // The class having the container
		/* Methods of user to handle what to do when going through the container */
		bool (User::*ShouldBeDeleted)(Contained*) ; // If the contained object is being deleted
		void (User::*Action)(Contained*);           // What to do if it shouldn't
		void (User::*Deletion)(Contained*);         // What to do when a contained should be deleted
		bool (User::*Filter)(Contained*);           // If the contained shouldn't be deleted, a filter to do or not the action method
		void (User::*Unfiltered)(Contained*);        // What to do if the element is unfiltered
	public:
		// Holy shit
	};
};

#endif
