#include "CollisionSystem.h"
#include "CollisionEvent.h"

#include <iostream>
#include <cassert>

void CollisionSystem::checkCollisions(const std::vector<Entity*>& colliders)
{
	// Identify Collisions
	std::set<std::pair<Entity*, Entity*>> collisions;
	for (auto it = colliders.begin(); it != colliders.end(); it++) 
	{
		for (auto jt = colliders.begin(); jt != colliders.end(); jt++) 
		{
			if (it != jt) 
			{
				if (dynamic_cast<CollisionComponent*>((*it)->getComponent(EntityComponent::COMPONENT_TYPE::Collision))->getColRect().getGlobalBounds().intersects(
					dynamic_cast<CollisionComponent*>((*jt)->getComponent(EntityComponent::COMPONENT_TYPE::Collision))->getColRect().getGlobalBounds()))
				{
					// minmax used so duplicates aren't inserted (ab same as ba)
					collisions.insert(std::minmax(*it, *jt));
				}
			}
		}
	}

	// Dispatch collision events to appropriate observer list(s)
	for (auto col : collisions)
	{
		// emit collision event
		std::cout << "Colision!" << std::endl;

		/* ENTITY_PICKUP Collision */
		if (col.first->getEntityType()  == Entity::ENTITY_TYPE::Pickup
		 || col.second->getEntityType() == Entity::ENTITY_TYPE::Pickup)
		{
			// update observers registered to listen for pickup event
			CollisionEvent* colEvent = new CollisionEvent(col.first, col.second);
			notify(colEvent, CollisionSystem::COLLISION_TYPE::ENTITY_PICKUP);
			delete colEvent;
		}

		/* ENTIY_WALL Collision */
	}



}
