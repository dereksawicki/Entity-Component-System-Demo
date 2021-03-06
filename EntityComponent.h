#ifndef ENTITY_COMPONENT_H
#define ENTITY_COMPONENT_H

#include <SFML/System/Time.hpp>

class EntityComponent
{
	friend class EntityFactory;

public:
	enum COMPONENT_TYPE {
		None
      , Suit
	  , Sprite
	  , Collision
	  , Pickup
	  , Input
	};

public:
	virtual void update(sf::Time delta) = 0;
	COMPONENT_TYPE getComponentType() { return mComponentType;  }

protected:
	COMPONENT_TYPE mComponentType;
};

#endif