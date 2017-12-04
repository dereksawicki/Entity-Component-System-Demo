#include "Renderer.h"
#include "CircleSuit.h"


void Renderer::render(sf::RenderWindow& window, Entity* entity)
{
	switch (entity->getEntityType())
	{
	case Entity::ENTITY_TYPE::Player:
	{
		// draw its renderable components
		CircleSuit* suit = dynamic_cast<CircleSuit*>(entity->getComponent(EntityComponent::CIRCLE_SUIT));
		window.draw(*suit);
		break;
	}
	default:
		break;
	}
}
