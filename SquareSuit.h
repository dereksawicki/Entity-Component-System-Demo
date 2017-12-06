#ifndef SQUARE_SUIT_H
#define SQUARE_SUIT_H

#include "SuitComponent.h"
#include <SFML/Graphics/RectangleShape.hpp>

class SquareSuit : public SuitComponent
{
public:
	SquareSuit();

	virtual void update(sf::Time dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
};

#endif