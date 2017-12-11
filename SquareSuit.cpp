#include "SquareSuit.h"


SquareSuit::SquareSuit(const sf::Color& color)
{
	mShape = new sf::RectangleShape(sf::Vector2f(35.f, 35.f));

	mShape->setFillColor(color);
	mColor = color;

	mComponentType = COMPONENT_TYPE::SUIT;
	mSuitType = ShapeComponent::SHAPE_TYPE::Square;
}

void SquareSuit::update(sf::Time dt)
{
}
