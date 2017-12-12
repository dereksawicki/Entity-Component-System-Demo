#include "EntityFactory.h"
#include "ShapeFactory.h"
#include "CircleSuit.h"
#include "RenderableComponent.h"
#include "CollisionComponent.h"
#include "PlayerInput.h"
#include "SpriteComponent.h"
#include "ToggleSuitPickup.h"

Entity* EntityFactory::getEntity(Entity::ENTITY_TYPE type, const sf::Texture& texture)
{
	switch (type)
	{
	case Entity::ENTITY_TYPE::Player:
	{
		Entity* entity = new Entity(Entity::ENTITY_TYPE::Player);
		// add things a player has
		ShapeComponent* suit = ShapeFactory::getSuit(ShapeComponent::SHAPE_TYPE::Circle);
		CollisionComponent* collisionComponent = new CollisionComponent(35.f, 35.f, entity);


		entity->setPosition(200.f, 200.f);
		entity->attachComponent(suit);
		entity->attachComponent(collisionComponent);


		return entity;
	}

	default:
		return nullptr;
	}
}