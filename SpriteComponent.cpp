#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(const sf::Texture& texture, const sf::IntRect& textureRect)
: mSprite(texture, textureRect)
{
	mComponentType = EntityComponent::COMPONENT_TYPE::SPRITE;
}

void SpriteComponent::update(sf::Time)
{

}

void SpriteComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
