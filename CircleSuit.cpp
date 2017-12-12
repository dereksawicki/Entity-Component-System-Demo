#include "CircleSuit.h"


CircleSuit::CircleSuit(const sf::Color& color)
{
	mShape = new sf::CircleShape(20.f);

	mShape->setFillColor(color);
	mColor = color;

	mComponentType = COMPONENT_TYPE::Suit;
	mSuitType = ShapeComponent::SHAPE_TYPE::Circle;
}

void CircleSuit::update(sf::Time dt)
{
}
