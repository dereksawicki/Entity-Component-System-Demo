#ifndef ENTITY_H
#define ENTITY_H

#include "EntityComponent.h"

#include <SFML/System/Time.hpp>

#include <unordered_map>

class Entity
{
	friend class EntityFactory;

public:
	enum ENTITY_TYPE {
		None
	  , Player
	};

	typedef std::unordered_map<EntityComponent::COMPONENT_TYPE, EntityComponent*> EntityComponents;
	

public:
	Entity(ENTITY_TYPE type);
	~Entity();


	virtual void update(sf::Time deltaTime) {}

	void attachComponent(EntityComponent* entityComponent);
	void detachComponent();
	EntityComponent* getComponent(EntityComponent::COMPONENT_TYPE type);

private:
	ENTITY_TYPE mEntityType;
	EntityComponents mComponents;

public:
	ENTITY_TYPE getEntityType() const
	{
		return mEntityType;
	}
};




#endif