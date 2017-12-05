#ifndef CIRCLE_SUIT_H
#define CIRCLE_SUIT_H

#include "SuitComponent.h"
#include <SFML/Graphics/CircleShape.hpp>

class CircleSuit : public SuitComponent
{
public:
	CircleSuit();

	virtual void update(sf::Time dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
};

#endif