#include "SquareSuit.h"


SquareSuit::SquareSuit()
{
	mShape = new sf::RectangleShape(sf::Vector2f(35.f, 35.f));

	mShape->setFillColor(sf::Color::Red);
	mComponentType = COMPONENT_TYPE::SUIT;
	mSuitType = ShapeComponent::SHAPE_TYPE::Square;
}

void SquareSuit::update(sf::Time dt)
{
}
