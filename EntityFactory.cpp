#include "EntityFactory.h"
#include "CircleSuit.h"
#include "SuitComponent.h"

Entity* EntityFactory::getEntity(Entity::ENTITY_TYPE type)
{
	switch (type)
	{
	case Entity::ENTITY_TYPE::Player:
	{
		Entity* newEntity = new Entity(Entity::ENTITY_TYPE::Player);
		// add things a player has
		SuitComponent* newSuit = new CircleSuit();

		newEntity->setPosition(200.f, 200.f);
		newEntity->attachComponent(newSuit);

		return newEntity;
	}
	default:
		return nullptr;
	}
}