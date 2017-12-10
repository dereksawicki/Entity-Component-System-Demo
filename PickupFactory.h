#ifndef PICKUP_FACTORY_H
#define PICKUP_FACTORY_H

#include "PickupComponent.h"
#include "CollisionSystem.h"

#include <SFML/Graphics/Texture.hpp>

class PickupFactory
{
public:
	static Entity* getPickup(PickupComponent::PICKUP_TYPE type, const sf::Texture& texture);
};


#endif