#ifndef ENTITY_COMPONENT_H
#define ENTITY_COMPONENT_H

#include <SFML/System/Time.hpp>

class EntityComponent
{
	friend class EntityFactory;

public:
	enum COMPONENT_TYPE {
		NONE
      , SUIT
	  , SPRITE
	  , COLLISION
	};

public:
	virtual void update(sf::Time delta) = 0;
	COMPONENT_TYPE getComponentId() { return mComponentType;  }

protected:
	COMPONENT_TYPE mComponentType;
};

#endif