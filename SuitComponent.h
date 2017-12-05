#ifndef SUIT_COMPONENT_H
#define SUIT_COMPONENT_H


#include "EntityComponent.h"
#include "VisualComponent.h"

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

/*
the player will be able to switch between a circle suit and a rectangle suit.
*/
class SuitComponent : public VisualComponent
{

protected:
	sf::Shape* mShape;


public:
	virtual ~SuitComponent() { delete mShape; }

	virtual void update(sf::Time dt) {};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const 
	{
		target.draw(*mShape, states);
	}


};

#endif