#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

#include <vector>
#include <map>
#include <cassert>

class Subject
{
public:
	void addObserver(unsigned int category, Observer* observer)
	{
		mObservers[category].push_back(observer);
	}
	void removeObserver(unsigned int category, Observer* observer)
	{
		auto find = std::find(mObservers[category].begin(), mObservers[category].end(), observer);
		assert(find != mObservers[category].end());

		mObservers[category].erase(find);
	}

	void notify(Entity* entity, Event* event, unsigned int category)
	{
		for (auto observer : mObservers[category])
		{
			observer->onNotify(entity, event);
		}
	}

private:
	std::map<unsigned int, std::vector<Observer*>> mObservers;
};


#endif