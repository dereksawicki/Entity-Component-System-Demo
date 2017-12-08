#include "Demo.h"
#include "EntityFactory.h"


#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>


Demo::Demo()
: //EventQueue()
 mWindow(sf::VideoMode(800, 600), "Demo", sf::Style::Close)
{
	mSpriteSheet.loadFromFile("Media/spritesheet.png");

	mPlayer = EntityFactory::getEntity(Entity::ENTITY_TYPE::Player, mCollisionSystem, mSpriteSheet);
	mToggleSuitPickup = EntityFactory::getEntity(Entity::ENTITY_TYPE::ToggleSuitPickup, mCollisionSystem, mSpriteSheet);

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

			sf::Event event;
			while (mWindow.pollEvent(event))
			{
				switch (event.type)
				{
					// if key pressed, emit key pressed event
					// event queue should receive it, notify
					// all observers.
				case sf::Event::Closed:
					mWindow.close();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Space) 
					{
						
					}
				default:
					break;
				}

				// handle events

			}

			float speed = 40.f * TIME_PER_FRAME.asSeconds();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				mPlayer->move(0.f, -speed);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				mPlayer->move(-speed, 0.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				mPlayer->move(0.f, speed);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				mPlayer->move(speed, 0.f);
			}


			mPlayer->update(TIME_PER_FRAME);
			mToggleSuitPickup->update(TIME_PER_FRAME);
			mCollisionSystem.update();

		}

		render();

	}
}

void Demo::render()
{
	mWindow.clear(sf::Color::Black);

	mRenderSystem.render(mWindow, mPlayer);
	mRenderSystem.render(mWindow, mToggleSuitPickup);

	mWindow.display();
}
