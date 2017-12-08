#include "CollisionSystem.h"

#include <iostream>
#include <cassert>

void CollisionSystem::update()
{
	for (auto it = mColliders.begin(); it != mColliders.end(); it++) 
	{
		for (auto jt = mColliders.begin(); jt != mColliders.end(); jt++) 
		{
			if (it != jt) {

				if ((*it)->getColRect().getGlobalBounds().intersects((*jt)->getColRect().getGlobalBounds()))
				{
					// emit collision event
					std::cout << "Colision!" << std::endl;
				}

			}
		}
	}
}

void CollisionSystem::addCollider(CollisionComponent* comp)
{
	mColliders.push_back(comp);
}

void CollisionSystem::removeCollider(CollisionComponent* comp)
{
	for (auto itr = mColliders.begin(); itr != mColliders.end(); itr++)
	{
		if (*itr == comp)
		{
			mColliders.erase(itr);
			return;
		}
	}

	// shouldn't be trying to delete non existent colliders
	assert(true);
}