#ifndef PICKUP_SPRITE_H
#define PICKUP_SPRITE_H

#include "SpriteComponent.h"

class PickupSprite : public SpriteComponent
{
public:
	using SpriteComponent::SpriteComponent;

	virtual void update(sf::Time deltaTime) 
	{
		mSprite.setRotation(0.5f);
	}

};

#endif