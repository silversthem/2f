#include "../../../include/2f/Time/Timer.hpp"

F2::Timer::Timer()
{
	setTickDelay(0);
	setTicksLoop(0);
	_currentCount = 0;
}

F2::Timer::Timer(int const& d,int const& loop)
{
	setTickDelay(d);
	setTicksLoop(loop);
	_currentCount = 0;
}

F2::Timer::~Timer()
{
	for(std::map<int,F2::Ticker*>::iterator it = _tickers.begin();it != _tickers.end();it++)
	{
		delete (it->second);
	}
}

void F2::Timer::setTickDelay(int const& d)
{
	_delay = d;
}

void F2::Timer::setTicksLoop(int const& l)
{
	_loop = l;
}

void F2::Timer::addTicker(int const& ticksRequired)
{
	_tickers[ticksRequired] = new F2::Ticker(ticksRequired);
}

void F2::Timer::addToTicker(int const& tick,Listener* l)
{
	if(_tickers.find(tick) == _tickers.end())
	{
		addTicker(tick);
	}
	_tickers[tick]->add(l);
}

F2::Ticker* F2::Timer::ticker(int const& index)
{
	F2::Ticker* t = 0;
	if(_tickers.find(index) != _tickers.end())
	{
		t = _tickers[index];
	}
	return t;
}

void F2::Timer::tick()
{
	if(_delay > 0 && _loop > 0)
	{
		calculate();
		// ...
	}

}

void F2::Timer::calculate()
{
	
}