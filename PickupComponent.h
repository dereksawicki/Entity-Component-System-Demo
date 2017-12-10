#ifndef PICKUP_COMPONENT_H
#define PICKUP_COMPONENT_H

#include "EntityComponent.h"
#include "Entity.h"

class PickupComponent : public EntityComponent
{
public:
	enum PICKUP_TYPE {
		None
	  , ToggleSuit
	};

public:
	virtual void update(sf::Time deltaTime) = 0;
	virtual void applyEffect(Entity* entity) = 0;

protected:
	PICKUP_TYPE mPickupType;
};


#endif