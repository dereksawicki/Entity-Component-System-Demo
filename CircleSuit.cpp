#include "CircleSuit.h"


CircleSuit::CircleSuit()
{
	mShape = new sf::CircleShape(20.f);

	mShape->setFillColor(sf::Color::Blue);
	mComponentType = COMPONENT_TYPE::SUIT;
	mSuitType = SuitComponent::SUIT_TYPE::Circle;
}

void CircleSuit::update(sf::Time dt)
{
}

void CircleSuit::draw(sf::RenderTarget &target, sf::RenderStates states) const 
{
	SuitComponent::draw(target, states);
}