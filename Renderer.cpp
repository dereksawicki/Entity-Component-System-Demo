#include "Renderer.h"
#include "SuitComponent.h"


void Renderer::render(sf::RenderWindow& window, Entity* entity)
{
	switch (entity->getEntityType())
	{
	case Entity::ENTITY_TYPE::Player:
	{
		// draw its renderable components
		SuitComponent* suit = dynamic_cast<SuitComponent*>(entity->getComponent(EntityComponent::SUIT));

		window.draw(*suit, sf::RenderStates(entity->getTransform()));
		break;
	}
	default:
		break;
	}
}
