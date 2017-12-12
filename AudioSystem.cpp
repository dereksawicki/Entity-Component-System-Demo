#include "AudioSystem.h"


AudioSystem::AudioSystem()
{

	mBuffer.loadFromFile("Media/pickup.wav");
	mPickupSound.setBuffer(mBuffer);
}

void AudioSystem::init(CollisionSystem& collisionSystem)
{
	collisionSystem.addObserver(this, CollisionSystem::COLLISION_TYPE::ENTITY_PICKUP );
}

void AudioSystem::onNotify(Event* event)
{
	mPickupSound.play();
}