#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "CollisionComponent.h"
#include "Subject.h"

#include <SFML/System/Time.hpp>

#include <set>
#include <vector>
/*

*/
class CollisionSystem : public Subject
{
public:
	enum COLLISION_TYPE {
		None
	  , ENTITY_PICKUP
	};

public:
	void checkCollisions(const std::vector<Entity*>& colliders);

};

#endif