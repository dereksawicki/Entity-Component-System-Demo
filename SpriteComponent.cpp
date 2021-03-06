#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(const sf::Texture& texture, const sf::IntRect& textureRect)
: mSprite(texture, textureRect)
{
	mComponentType = EntityComponent::COMPONENT_TYPE::Sprite;
	mSprite.setOrigin(textureRect.width / 2, textureRect.height / 2);
}

void SpriteComponent::update(sf::Time)
{

}

void SpriteComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
