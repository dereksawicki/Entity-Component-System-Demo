#include "PlayerInput.h"
#include "InputEvent.h"

#include "SFML/Window/Keyboard.hpp">

#include <iostream>

PlayerInput::PlayerInput(Entity* parent)
{
	mParent = parent;
	mComponentType = EntityComponent::COMPONENT_TYPE::Input;
}


void PlayerInput::onNotify(Event* event)
{
	// if received, it must be an input event
	InputEvent* inputEvent = dynamic_cast<InputEvent*>(event);
	switch (inputEvent->mEvent.type)
	{
	case sf::Event::KeyPressed:
		if (inputEvent->mEvent.key.code == sf::Keyboard::Space)
		{
			std::cout << "Space pressed!" << std::endl;
		}
		break;
	default:
		break;
	}
}

void PlayerInput::update(sf::Time deltaTime)
{
	float speed = 70.f * deltaTime.asSeconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		mParent->move(0.f, -speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		mParent->move(-speed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		mParent->move(0.f, speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		mParent->move(speed, 0.f);
	}
}

