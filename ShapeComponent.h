#ifndef SHAPE_COMPONENT_H
#define SHAPE_COMPONENT_H


#include "EntityComponent.h"
#include "RenderableComponent.h"

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Color.hpp>

/*
the player will be able to switch between a circle suit and a rectangle suit.
*/
class ShapeComponent : public RenderableComponent
{
public:
	enum SHAPE_TYPE {
		None, Circle, Square
	};

public:
	virtual ~ShapeComponent() { delete mShape; }

	virtual void update(sf::Time dt) {};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const 
	{
		target.draw(*mShape, states);
	}

	SHAPE_TYPE getType() {
		return mSuitType;
	}

	const sf::Color& getColor() { return mColor; }
	void setColor(const sf::Color& col) { mShape->setFillColor(col); mColor = col; }

protected:
	sf::Shape* mShape;
	SHAPE_TYPE mSuitType;
    sf::Color mColor;

};

#endif