#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

#include <vector>
#include <map>
#include <cassert>

class Subject
{
public:
	void addObserver(Observer* observer, unsigned int category)
	{
		mObservers[category].push_back(observer);
	}
	void removeObserver(Observer* observer, unsigned int category)
	{
		auto find = std::find(mObservers[category].begin(), mObservers[category].end(), observer);
		assert(find != mObservers[category].end());

		mObservers[category].erase(find);
	}

	void notify(Event* event, unsigned int category)
	{
		for (auto observer : mObservers[category])
		{
			observer->onNotify(event);
		}
	}

private:
	std::map<unsigned int, std::vector<Observer*>> mObservers;
};


#endif