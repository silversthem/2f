/*
 * A keyBinder is an actionBinder for key events.
 * State is controlled by press/release events, you can choose which is which.
 * A key binder memorizes 1 key, and can use a filter method.
 */

#ifndef KEYBINDER_HPP
#define KEYBINDER_HPP

/* 2f */
#include "ObjectBinder.hpp"

namespace F2
{
	template<typename ObjectType>
	class KeyBinder : public ObjectBinder<ObjectType,sf::Event>
	{
	protected:
		bool _onPress; // True -> activates on press, False -> activates on release
		std::function<void (ObjectType*)> _userFilter; // user filter, if needed
		sf::Keyboard::Key _key; // The key which this is bounded to
	public:
		KeyBinder(bool const& press = true) // Creates a keyBinder
		{
			set_onPress(press);
		}
		void set_onPress(bool const& press) // Whether the action activates on key press or release
		{
			_onPress = press;
		}
		void set_filter(std::function<void (ObjectType*)> const& userFilter) // Sets the user filter
		{
			_userFilter = userFilter;
		}
		void set_key(sf::Keyboard::Key const& key) // Sets binding key
		{
			_key = key;
		}
		void action(sf::Event const& event) // key event
		{
			if(_userFilter && !_userFilter(_object)) // User filter failed
			{
				return;
			}
			if(_onPress && event.type == sf::Event::KeyPressed || !_onPress && event.type == sf::Event::KeyReleased)
			{
				if(event.key.code != _key) // Wrong key
				{
					return;
				}
			}
			ObjectBinder<ObjectType,sf::Event>::action(event);
		}
	};
};

#endif