#include "Demo.h"
#include "EntityFactory.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>


Demo::Demo()
: //EventQueue()
 mWindow(sf::VideoMode(800, 600), "Demo", sf::Style::Close)
{
	player = EntityFactory::getEntity(Entity::ENTITY_TYPE::Player);

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
				default:
					break;
				}

				// handle events
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
				}
			}


		}

		render();

	}
}

void Demo::render()
{
	mWindow.clear(sf::Color::Black);

	renderer.render(mWindow, player);

	mWindow.display();
}
