#ifndef COLLISION_COMPONENT_H
#define COLLISION_COMPONENT_H

#include "EntityComponent.h"
#include "Entity.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>

class CollisionComponent : public EntityComponent
{
public:
	CollisionComponent(float width, float height, Entity* entity);

	virtual void update(sf::Time deltaTime);

	const sf::RectangleShape& getColRect() { return mCollisionRect; }
	Entity* getEntity() { return mEntity;  }

private:
	sf::RectangleShape mCollisionRect;
	Entity* mEntity;
};

#endif