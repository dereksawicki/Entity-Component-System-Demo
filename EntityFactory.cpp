#include "EntityFactory.h"
#include "CircleSuit.h"
#include "SuitFactory.h"

Entity* EntityFactory::getEntity(Entity::ENTITY_TYPE type)
{
	switch (type)
	{
	case Entity::ENTITY_TYPE::Player:
	{
		Entity* newEntity = new Entity(Entity::ENTITY_TYPE::Player);
		// add things a player has
		SuitComponent* newSuit = SuitFactory::getSuit(SuitComponent::SUIT_TYPE::Circle);

		newEntity->setPosition(200.f, 200.f);
		newEntity->attachComponent(newSuit);

		return newEntity;
	}
	default:
		return nullptr;
	}
}