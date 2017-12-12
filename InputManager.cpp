#include "InputManager.h"
#include "InputEvent.h"

#include <SFML/Window/Event.hpp>

#include <iostream>

void InputManager::pollEvents(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			// if key pressed, emit key pressed event
			// event queue should receive it, notify
			// all observers.
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
		{
			InputEvent* iEvent = new InputEvent(event);
			notify(iEvent, InputManager::INPUT_TYPES::All);
			delete iEvent;
		}
		}
	}
}