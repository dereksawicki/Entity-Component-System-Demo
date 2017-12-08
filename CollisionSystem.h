#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "CollisionComponent.h"

#include <SFML/System/Time.hpp>

#include <vector>
/*

*/
class CollisionSystem
{
public:
	void update();

	void addCollider(CollisionComponent* comp);
	void removeCollider(CollisionComponent* comp);

private:
	std::vector<CollisionComponent*> mColliders;
};

#endif