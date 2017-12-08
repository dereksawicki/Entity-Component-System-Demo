#include "EntityFactory.h"
#include "CircleSuit.h"
#include "CollisionComponent.h"
#include "ShapeFactory.h"
#include "PickupSprite.h"
#include "RenderableComponent.h"
#include "SpriteComponent.h"
#include "ToggleSuitPickup.h"

Entity* EntityFactory::getEntity(Entity::ENTITY_TYPE type, CollisionSystem& collisionSystem, const sf::Texture& texture)
{
	switch (type)
	{
	case Entity::ENTITY_TYPE::Player:
	{
		Entity* entity = new Entity(Entity::ENTITY_TYPE::Player);
		// add things a player has
		ShapeComponent* suit = ShapeFactory::getSuit(ShapeComponent::SHAPE_TYPE::Circle);
		CollisionComponent* collisionComponent = new CollisionComponent(35.f, 35.f, entity);
		collisionSystem.addCollider(collisionComponent);

		entity->setPosition(200.f, 200.f);
		entity->attachComponent(suit);
		entity->attachComponent(collisionComponent);
		

		return entity;
	}
	case Entity::ENTITY_TYPE::ToggleSuitPickup:
	{
		Entity* entity = new Entity(Entity::ENTITY_TYPE::ToggleSuitPickup);

		// these have a transform, a sprite, a collider, and a pickup
		CollisionComponent* collisionComponent = new CollisionComponent(35.f, 35.f, entity);
		RenderableComponent* spriteComponent = new PickupSprite(texture, sf::IntRect(0, 0, 63, 63));

		collisionSystem.addCollider(collisionComponent);

		entity->setPosition(100.f, 50.f);
		entity->attachComponent(collisionComponent);
		entity->attachComponent(spriteComponent);

		return entity;
		
	}
	default:
		return nullptr;
	}
}