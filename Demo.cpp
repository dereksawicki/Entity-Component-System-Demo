#include "Demo.h"
#include "EntityFactory.h"


#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <vector>

Demo::Demo()
	: //EventQueue()
	mWindow(sf::VideoMode(800, 600), "Demo", sf::Style::Close)
{
	mSpriteSheet.loadFromFile("Media/spritesheet.png");

	mPickupSystem.init(mCollisionSystem, mSpriteSheet);
	mAudioSystem.init(mCollisionSystem);


	mActorSystem.init(mCollisionSystem, mSpriteSheet, mInputManager);
}

void Demo::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			timeSinceLastUpdate -= TIME_PER_FRAME;

			mInputManager.pollEvents(mWindow);

			mActorSystem.update(TIME_PER_FRAME);
			mPickupSystem.update(TIME_PER_FRAME);

			// Check Collisions
			std::vector<Entity*> colliders;
			auto pickups = mPickupSystem.getPickups();
			auto actors = mActorSystem.getActors();
			colliders.insert(colliders.end(), pickups.begin(), pickups.end());
			colliders.insert(colliders.end(), actors.begin(), actors.end());
			mCollisionSystem.checkCollisions(colliders);

		}

		render();

	}
}

void Demo::render()
{
	mWindow.clear(sf::Color::Black);

	mActorSystem.render(mWindow, mRenderSystem);
	mPickupSystem.render(mWindow, mRenderSystem);

	mWindow.display();
}
