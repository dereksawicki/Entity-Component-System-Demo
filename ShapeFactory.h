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
			return new CircleSuit(sf::Color::Blue);
		}
		case ShapeComponent::SHAPE_TYPE::Square:
		{
			return new SquareSuit(sf::Color::Blue);
		}
		default:
			return new CircleSuit(sf::Color::Blue);
		}
	}


	static void exchangeSuit(Entity* entity)
	{
		ShapeComponent* shapeComponent = dynamic_cast<ShapeComponent*>(entity->getComponent(EntityComponent::COMPONENT_TYPE::Suit));
		ShapeComponent::SHAPE_TYPE type = shapeComponent->getType();
		sf::Color oldColor = shapeComponent->getColor();
		
		entity->detachComponent(EntityComponent::COMPONENT_TYPE::Suit);
		if (type == ShapeComponent::SHAPE_TYPE::Circle)
		{
			entity->attachComponent(new SquareSuit(oldColor));
		}
		else 
		{
			entity->attachComponent(new CircleSuit(oldColor));
		}
	}

	static void exchangeColor(Entity* entity)
	{
		ShapeComponent* shapeComponent = dynamic_cast<ShapeComponent*>(entity->getComponent(EntityComponent::COMPONENT_TYPE::Suit));

		sf::Color color = shapeComponent->getColor();
		if (color == sf::Color::Blue) 
		{
			shapeComponent->setColor(sf::Color::Red);
		}
		else
		{
			shapeComponent->setColor(sf::Color::Blue);
		}
	}

};

#endif