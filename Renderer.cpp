#include "RenderSystem.h"
#include "ShapeComponent.h"
#include "SpriteComponent.h"


void RenderSystem::render(sf::RenderWindow& window, Entity* entity)
{
	switch (entity->getEntityType())
	{
	case Entity::ENTITY_TYPE::Player:
	{
		// draw its renderable components
		ShapeComponent* suit = dynamic_cast<ShapeComponent*>(entity->getComponent(EntityComponent::SUIT));

		window.draw(*suit, sf::RenderStates(entity->getTransform()));
		break;
	}
	case Entity::ENTITY_TYPE::Pickup:
	{
		SpriteComponent* sprite = dynamic_cast<SpriteComponent*>(entity->getComponent(EntityComponent::COMPONENT_TYPE::SPRITE));
	
		window.draw(*sprite, sf::RenderStates(entity->getTransform()));
	}
	default:
		break;
	}
}
