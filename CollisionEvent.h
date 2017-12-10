#ifndef COLLISION_EVENT_H
#define COLLISION_EVENT_H

#include "Event.h"
#include "Entity.h"

class CollisionEvent : public Event
{

public:
	CollisionEvent(Entity* entity1, Entity* entity2)
	{
		mEventType = Event::EVENT_TYPE::Collision;
		mEntities[0] = entity1;
		mEntities[1] = entity2;
	}

	Entity* mEntities[2];
};

#endif