#ifndef RENDERABLE_COMPONENT_H
#define RENDERABLE_COMPONENT_H
#include "EntityComponent.h"

#include <SFML/Graphics/Drawable.hpp>

class RenderableComponent : public EntityComponent, public sf::Drawable

{
public:
	virtual void update(sf::Time) {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) {}

private:

};

#endif