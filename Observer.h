#ifndef OBSERVER_H
#define OBSERVER_H

#include "Event.h"
#include "Entity.h"

class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(Entity* entity, Event* event) = 0;
};


#endif