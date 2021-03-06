#include "../../../include/2f/Binders/EventBinder.hpp"

F2::EventBinder::EventBinder()
{
	
}

/* Protected listeners methods */

void F2::EventBinder::handle(sf::Event *e)
{
	if(_binders.find(e->type) != _binders.end())
	{
		std::for_each(_binders[e->type].begin(),_binders[e->type].end(),[e](std::pair<std::string,F2::Callable<sf::Event*>*> p){
			p.second->exec(e);
		});
	}
	F2::Listener::handle(e);
}

void F2::EventBinder::onTicked(int const& tick)
{
	std::for_each(_timers.begin(),_timers.end(),[tick](std::pair<std::string,F2::Callable<int>*> p){
		p.second->exec(tick);
	});
	F2::Listener::onTicked(tick);
}

/* Protected Adders */

F2::Callable<sf::Event*>* F2::EventBinder::add(std::function<void (sf::Event*)> &f)
{
	_storage.push_back(Callable<sf::Event*>(f));
	return &(*(_storage.end() - 1));
}

void F2::EventBinder::del()
{
	
}

/* Adders */

void F2::EventBinder::bind(sf::Event::EventType const& t,std::string const& name,std::function<void (sf::Event*)> f)
{
	if(_binders.find(t) == _binders.end())
	{
		std::map<std::string,Callable<sf::Event*>*> m;
		_binders[t] = m;
	}
	_binders[t][name] = add(f);
}

void F2::EventBinder::bind(std::string const& name,std::function<void (int)> &f)
{
	
}

void F2::EventBinder::key_bind(std::string const& name,std::function<void (sf::Event*)> &f)
{
	 bind(sf::Event::KeyPressed,name,f);
	bind(sf::Event::KeyReleased,name,f);
}

/* Deleters */

void F2::EventBinder::event_unbind(std::string const& name)
{
	for(auto it : _binders)
	{
		for(auto it2 : it.second)
		{
			_binders[it.first].erase(name);
		}
	}
}

void F2::EventBinder::timer_unbind(std::string const& name)
{
	_timers.erase(name);
}

/* Getters */

F2::Callable<sf::Event*>* F2::EventBinder::event_binded(std::string const& name)
{
	for(auto it : _binders)
	{
		for(auto it2 : it.second)
		{
			if(it2.first == name)
			{
				return it2.second;
			}
		}
	}
	throw;
}

F2::Callable<int>* F2::EventBinder::timer_binded(std::string const& name)
{
	for(auto it : _timers)
	{
		if(it.first == name)
		{
			return it.second;
		}
	}
	throw;
}