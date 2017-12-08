#ifndef CIRCLE_SUIT_H
#define CIRCLE_SUIT_H

#include "ShapeComponent.h"
#include <SFML/Graphics/CircleShape.hpp>

class CircleSuit : public ShapeComponent
{
public:
	CircleSuit();

	virtual void update(sf::Time dt);

};

#endif