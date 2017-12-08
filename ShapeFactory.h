#ifndef SUIT_FACTORY_H
#define SUIT_FACTORY_H

#include "ShapeComponent.h"
#include "Entity.h"
#include "CircleSuit.h"
#include "SquareSuit.h"

class ShapeFactory
{
public:

	static ShapeComponent* getSuit(ShapeComponent::SHAPE_TYPE type)
	{
		switch (type) {
		case ShapeComponent::SHAPE_TYPE::Circle:
		{
			return new CircleSuit();
		}
		case ShapeComponent::SHAPE_TYPE::Square:
		{
			return new SquareSuit();
		}
		default:
			return new CircleSuit();
		}
	}


	static void exchangeSuit(Entity* entity)
	{
		ShapeComponent::SHAPE_TYPE type = dynamic_cast<ShapeComponent*>(entity->getComponent(EntityComponent::COMPONENT_TYPE::SUIT))->getType();
		entity->detachComponent(EntityComponent::COMPONENT_TYPE::SUIT);
		if (type == ShapeComponent::SHAPE_TYPE::Circle)
		{
			entity->attachComponent(new SquareSuit());
		}
		else {
			entity->attachComponent(new CircleSuit());
		}
	}

};

#endif