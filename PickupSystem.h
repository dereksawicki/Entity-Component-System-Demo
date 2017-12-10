#ifndef PICKUP_SYSTEM_H
#define PICKUP_SYSTEM_H

#include "PickupFactory.h"
#include "Observer.h"
#include "RenderSystem.h"

#include <SFML/System/Time.hpp>

// pickup system observes collision system directly for now
// in the future, it will observe the eventsystem
// pickup system responsibilities: handle interactions between entities and pickups, destroy pickups, create pickups
class PickupSystem : public Observer
{
public:
	PickupSystem();
	~PickupSystem();

	void init(CollisionSystem& collisionSystem, const sf::Texture& texture);

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow& window, const RenderSystem& renderSystem);


	virtual void onNotify(Entity* entity, Event* event);
	const std::vector<Entity*>& getPickups();

private:
	void destroyPickup(Entity* entity);

private:
	std::vector<Entity*> mPickups;
};


#endif