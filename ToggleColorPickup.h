#ifndef TOGGLE_COLOR_PICKUP_H
#define TOGGLE_COLOR_PICKUP_H

#include "ShapeFactory.h"
#include "PickupComponent.h"

class ToggleColorPickup : public PickupComponent
{
public:
	ToggleColorPickup()
	{
		mComponentType = EntityComponent::COMPONENT_TYPE::Pickup;
		mPickupType = PickupComponent::PICKUP_TYPE::ToggleColor;
	}

	void update(sf::Time deltaTime) {}; // update state

	void applyEffect(Entity* entity)
	{
		ShapeFactory::exchangeColor(entity);
	}

private:
	// state
};

#endif