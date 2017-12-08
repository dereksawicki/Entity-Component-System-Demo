#ifndef PICKUP_FACTORY_H
#define PICKUP_FACTORY_H

#include "PickupComponent.h"

class PickupFactory
{

public:
	enum PICKUP_TYPE {
		None
	  , ToggleSuit
	  , ToggleColor
	};

public:
	PickupComponent* getPickup(PICKUP_TYPE type);
};


#endif