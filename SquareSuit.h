#ifndef SQUARE_SUIT_H
#define SQUARE_SUIT_H

#include "ShapeComponent.h"
#include <SFML/Graphics/RectangleShape.hpp>

class SquareSuit : public ShapeComponent
{
public:
	SquareSuit(const sf::Color& color);

	virtual void update(sf::Time dt);
};

#endif