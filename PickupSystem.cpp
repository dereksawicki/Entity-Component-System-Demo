#include "PickupSystem.h"
#include "EntityFactory.h"
#include "CollisionEvent.h"
#include "PickupFactory.h"

#include <iostream>

PickupSystem::PickupSystem()
{
}

PickupSystem::~PickupSystem() 
{
	for (auto e : mPickups)
		delete e;

	mPickups.clear();
}

void PickupSystem::init(CollisionSystem& collisionSystem, const sf::Texture& texture)
{
	// listen for pickup collisions
	collisionSystem.addObserver(CollisionSystem::COLLISION_TYPE::ENTITY_PICKUP, this);

	// create initial pickups
	Entity* pickup = PickupFactory::getPickup(PickupComponent::PICKUP_TYPE::ToggleSuit, texture);
	Entity* pickup2 = PickupFactory::getPickup(PickupComponent::PICKUP_TYPE::ToggleSuit, texture);
	pickup->setPosition(100.f, 50.f);
	pickup2->setPosition(150.f, 100.f);
	mPickups.push_back(pickup);
	mPickups.push_back(pickup2);
}

void PickupSystem::update(sf::Time deltaTime)
{
	// randomly generate pickups

	// update pickups
	for (auto p : mPickups)
	{
		p->rotate(2.f);
		p->update(deltaTime);
	}
}

void PickupSystem::render(sf::RenderWindow& window, const RenderSystem& renderSystem)
{
	for (auto p : mPickups)
	{
		renderSystem.render(window, p);
	}
}

void PickupSystem::destroyPickup(Entity* entity)
{
	// destroy pickup
	auto find = std::find(mPickups.begin(), mPickups.end(), entity);
	assert(find != mPickups.end());

	delete *find;
	mPickups.erase(find);
}


void PickupSystem::onNotify(Entity* entity, Event* event)
{
	std::cout << "Pickup collision!" << std::endl;
	switch (event->getEventType())
	{
	case Event::EVENT_TYPE::Collision:
		CollisionEvent* collisionEvent = dynamic_cast<CollisionEvent*>(event);

		if (collisionEvent->mEntities[0]->getEntityType() == Entity::ENTITY_TYPE::Pickup)
		{
			dynamic_cast<PickupComponent*>(
				collisionEvent->mEntities[0]->getComponent(EntityComponent::COMPONENT_TYPE::PICKUP))->applyEffect(collisionEvent->mEntities[1]);
			destroyPickup(collisionEvent->mEntities[0]);
		}
		else
		{
			dynamic_cast<PickupComponent*>(
				collisionEvent->mEntities[1]->getComponent(EntityComponent::COMPONENT_TYPE::PICKUP))->applyEffect(collisionEvent->mEntities[0]);
			destroyPickup(collisionEvent->mEntities[1]);
		}
	}
}

const std::vector<Entity*>& PickupSystem::getPickups()
{
	return mPickups;
}