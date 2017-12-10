#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "Entity.h"
#include "CollisionSystem.h"

#include <SFML/Graphics/Texture.hpp>

class EntityFactory {

public:
	static Entity* getEntity(Entity::ENTITY_TYPE type,  const sf::Texture& texture);

};


#endif