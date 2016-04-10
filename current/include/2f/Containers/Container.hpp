/*
 * A container is an array of pointers that handle deleting on the fly
 * When you have multiple vectors of pointers containing a pointer to the same object, this comes in handy
 * Note : this class is abstract, you have to fill in your own deletion criteria for the contained
 * Also : The function to execute in deletion and in "normal" are to be filled by you
 * Also : This class can be instanced via a macro, because normally it's really bad and ugly
 */

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <vector>

#define CONTAINER(x,y) Container<std::vector<x*>,std::vector<x*>::iterator,x,y> // Easily creates a container

namespace F2
{
	template<typename Vector,class Iter,typename Contained,class User>
	class Container
	{
	protected:
		Vector _vec; // Vector of contained stuff
		Iter it;     // Iterator to go through that stuff
		User* _user; // The class having the container
		/* Methods of user to handle what to do when going through the container */
		bool (User::*_ShouldBeDeleted)(Contained*); // If the contained object is being deleted
		void (User::*_Action)(Contained*);          // What to do if it shouldn't
		void (User::*_Deletion)(Contained*);        // What to do when a contained should be deleted
		bool (User::*_Filter)(Contained*);          // If the contained shouldn't be deleted, a filter to do or not the action method
		void (User::*_Unfiltered)(Contained*);      // What to do if the element is unfiltered
	public:
		Container() // Creates a container
		{
			_ShouldBeDeleted = 0;
			_Action          = 0;
			_Deletion        = 0;
			_Filter          = 0;
			_Unfiltered      = 0;
			_user            = 0;
		}
		/* Getters */
		Vector* vec() // Returns the vector
		{
			return *_vec;
		}
		/* Setters */
		void setUserObject(User* u) // Sets the object using the container
		{
			_user = u;
		}
		/* Method setters */
		void setDeletionTestMethod(bool (User::*ShouldBeDeleted)(Contained*))
		{
			_ShouldBeDeleted = ShouldBeDeleted;
		}
		void setDeletionMethod(void (User::*Action)(Contained*))
		{
			_Action = Action;
		}
		void setActionMethdod(void (User::*Deletion)(Contained*))
		{
			_Deletion = Deletion;
		}
		void setFilterMehod(bool (User::*Filter)(Contained*))
		{
			_Filter = Filter;
		}
		void setUnfilteredMethod(void (User::*Unfiltered)(Contained*))
		{
			_Unfiltered = Unfiltered;
		}
		/* Methods */
		virtual void go_through() // Goes through each container element
		{
			it = _vec.begin();
			for(;it != _vec.end();)
			{
				if(_ShouldBeDeleted != 0 && _user._ShouldBeDeleted(*it)) // If we should delete this element
				{
					if(_Deletion != 0)
					{
						_user._Deletion(*it); // Deleting it
					}
				}
				else
				{
					if(_Filter == 0 || _user._Filter(*it)) // If we should execute the action on element
					{
						_user._Action(*it);
					}
					else if(_Unfiltered != 0) // If we "unfilter" the element
					{
						_user._Unfiltered(*it);
					}
					it++;
				}
			}
		}
	};
};

#endif
