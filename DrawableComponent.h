#ifndef DRAWABLE_COMPONENT_H
#define DRAWABLE_COMPONENT_H


#include "EntityComponent.h"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

class DrawableComponent : public EntityComponent, public sf::Drawable, public sf::Transformable
{
public:
	virtual void update(sf::Time dt) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

#endif