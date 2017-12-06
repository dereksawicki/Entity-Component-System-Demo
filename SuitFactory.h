#ifndef SUIT_FACTORY_H
#define SUIT_FACTORY_H

#include "SuitComponent.h"
#include "CircleSuit.h"
#include "SquareSuit.h"

class SuitFactory
{
public:

	static SuitComponent* getSuit(SuitComponent::SUIT_TYPE type)
	{
		switch (type) {
		case SuitComponent::SUIT_TYPE::Circle:
		{
			return new CircleSuit();
		}
		case SuitComponent::SUIT_TYPE::Square:
		{
			return new SquareSuit();
		}
		default:
			return new CircleSuit();
		}
	}


	static void exchangeSuit(Entity* entity)
	{
		SuitComponent::SUIT_TYPE type = dynamic_cast<SuitComponent*>(entity->getComponent(EntityComponent::COMPONENT_TYPE::SUIT))->getType();
		entity->detachComponent(EntityComponent::COMPONENT_TYPE::SUIT);
		if (type == SuitComponent::SUIT_TYPE::Circle)
		{
			entity->attachComponent(new SquareSuit());
		}
		else {
			entity->attachComponent(new CircleSuit());
		}
	}



};

#endif