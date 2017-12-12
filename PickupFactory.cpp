#include "PickupFactory.h"
#include "ToggleSuitPickup.h"
#include "ToggleColorPickup.h"
#include "CollisionComponent.h"
#include "PickupSprite.h"


Entity* PickupFactory::getPickup(PickupComponent::PICKUP_TYPE type, const sf::Texture& texture)
{
	switch (type)
	{
	case PickupComponent::PICKUP_TYPE::ToggleSuit:
	{
		Entity* entity = new Entity(Entity::ENTITY_TYPE::Pickup);

		// these have a transform, a sprite, a collider, and a pickup
		CollisionComponent* collisionComponent = new CollisionComponent(35.f, 35.f, entity);
		RenderableComponent* spriteComponent = new PickupSprite(texture, sf::IntRect(0, 0, 63, 63));
		PickupComponent* toggleSuitPickup = new ToggleSuitPickup();

		entity->attachComponent(collisionComponent);
		entity->attachComponent(spriteComponent);
		entity->attachComponent(toggleSuitPickup);

		return entity;

		break;
	}
	case PickupComponent::PICKUP_TYPE::ToggleColor:
	{
		Entity* entity = new Entity(Entity::ENTITY_TYPE::Pickup);

		// these have a transform, a sprite, a collider, and a pickup
		CollisionComponent* collisionComponent = new CollisionComponent(35.f, 35.f, entity);
		RenderableComponent* spriteComponent = new PickupSprite(texture, sf::IntRect(64, 0, 63, 63));
		PickupComponent* toggleColorPickup = new ToggleColorPickup();

		entity->attachComponent(collisionComponent);
		entity->attachComponent(spriteComponent);
		entity->attachComponent(toggleColorPickup);

		return entity;

		break;
	}
	default:
		return NULL;
	}

}