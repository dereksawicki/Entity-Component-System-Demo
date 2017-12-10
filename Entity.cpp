#include "Entity.h"

#include <cassert>

Entity::Entity(ENTITY_TYPE type)
	: mEntityType(type)
{

}

Entity::~Entity()
{
	for (auto itr = mComponents.begin(); itr != mComponents.end(); ++itr)
	{
		delete itr->second;
	}
}

void Entity::update(sf::Time deltaTime)
{
	for (auto component : mComponents)
	{
		component.second->update(deltaTime);
	}
}

void Entity::attachComponent(EntityComponent* entityComponent)
{
	mComponents[entityComponent->getComponentType()] = entityComponent;
}

EntityComponent* Entity::getComponent(EntityComponent::COMPONENT_TYPE type)
{
	auto found = mComponents.find(type);
	// shouldn't be searching for nonexistent components
	assert(found != mComponents.end()); 

	return found->second;
}

void Entity::detachComponent(EntityComponent::COMPONENT_TYPE type)
{
	auto found = mComponents.find(type);

	assert(found != mComponents.end());

	delete found->second;
	mComponents.erase(found);
}
