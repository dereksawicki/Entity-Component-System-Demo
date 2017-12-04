#include "EntityFactory.h"
#include "CircleSuit.h"

Entity* EntityFactory::getEntity(Entity::ENTITY_TYPE type)
{
	switch (type)
	{
	case Entity::ENTITY_TYPE::Player:
	{
		Entity* newEnt = new Entity(Entity::ENTITY_TYPE::Player);
		// add things a player has
		CircleSuit* newSuit = new CircleSuit();
		newSuit->setPosition(200.f, 200.f);
		newEnt->attachComponent(newSuit);


		return newEnt;
	}
	default:
		return nullptr;
	}
}