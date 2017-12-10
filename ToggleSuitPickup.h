#ifndef TOGGLE_SUIT_PICKUP
#define TOGGLE_SUIT_PICKUP

#include "ShapeFactory.h"
#include "PickupComponent.h"

class ToggleSuitPickup : public PickupComponent
{
public:
	ToggleSuitPickup() 
	{
		mComponentType = EntityComponent::COMPONENT_TYPE::PICKUP;
		mPickupType = PickupComponent::PICKUP_TYPE::ToggleSuit;
	}

	void update(sf::Time deltaTime) {}; // update state

	void applyEffect(Entity* entity)
	{
		ShapeFactory::exchangeSuit(entity);
	}

private:
	// state
};


#endif