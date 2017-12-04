#ifndef CIRCLE_SUIT_H
#define CIRCLE_SUIT_H

#include "DrawableComponent.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Transformable.hpp>

class CircleSuit : public DrawableComponent
{
public:
	CircleSuit();

	virtual void update(sf::Time dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::CircleShape mCircleShape;
};

#endif