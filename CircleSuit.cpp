#include "CircleSuit.h"


CircleSuit::CircleSuit()
{
	mShape = new sf::CircleShape(20.f);

	mShape->setFillColor(sf::Color::Blue);
	mComponentType = COMPONENT_TYPE::SUIT;
	mSuitType = ShapeComponent::SHAPE_TYPE::Circle;
}

void CircleSuit::update(sf::Time dt)
{
}
