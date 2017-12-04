#include "CircleSuit.h"


CircleSuit::CircleSuit()
: mCircleShape(20.f)
{
	mCircleShape.setFillColor(sf::Color::Blue);
	mComponentType = COMPONENT_TYPE::CIRCLE_SUIT;
}

void CircleSuit::update(sf::Time dt)
{

}

void CircleSuit::draw(sf::RenderTarget &target, sf::RenderStates states) const 
{
	target.draw(mCircleShape, states);
}