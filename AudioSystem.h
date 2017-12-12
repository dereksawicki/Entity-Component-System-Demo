#ifndef AUDIO_SYSTEM_H
#define AUDIO_SYSTEM_H

#include "Observer.h"
#include "CollisionSystem.h"

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

/* audio system subscribes to collision system, listening for events. */
class AudioSystem : public Observer
{
public:
	AudioSystem();

	void init(CollisionSystem& collisionSystem);
	virtual void onNotify(Event* event);

private:
	//sounds
	sf::SoundBuffer mBuffer;
	sf::Sound mPickupSound;
};

#endif