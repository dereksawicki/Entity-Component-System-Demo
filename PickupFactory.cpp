#include "PickupFactory.h"
#include "ToggleSuitPickup.h"

PickupComponent* PickupFactory::getPickup(PickupFactory::PICKUP_TYPE type)
{


	switch (type)
	{
	case PickupFactory::PICKUP_TYPE::ToggleSuit:
	{
		PickupComponent* toggleSuitPickup = new ToggleSuitPickup();
		return toggleSuitPickup;

		break;
	}
	}

}