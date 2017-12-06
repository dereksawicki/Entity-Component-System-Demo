#include "SquareSuit.h"


SquareSuit::SquareSuit()
{
	mShape = new sf::RectangleShape(sf::Vector2f(35.f, 35.f));

	mShape->setFillColor(sf::Color::Red);
	mComponentType = COMPONENT_TYPE::SUIT;
	mSuitType = SuitComponent::SUIT_TYPE::Square;
}

void SquareSuit::update(sf::Time dt)
{
}

void SquareSuit::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	SuitComponent::draw(target, states);
}