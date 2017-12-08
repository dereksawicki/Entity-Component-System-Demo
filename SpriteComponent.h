#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "RenderableComponent.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


class SpriteComponent : public RenderableComponent
{
public:
	SpriteComponent(const sf::Texture& texture, const sf::IntRect& textureRect);

	virtual void update(sf::Time);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
	sf::Sprite mSprite;
};

#endif