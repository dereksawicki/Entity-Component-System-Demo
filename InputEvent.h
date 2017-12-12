#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

#include "Event.h"

#include <SFML/Window/Event.hpp>

class InputEvent : public Event
{
public:
	InputEvent(const sf::Event& event)
	{
		mEventType = Event::EVENT_TYPE::Input;
		mEvent = event;
	}

	sf::Event mEvent;
};

#endif