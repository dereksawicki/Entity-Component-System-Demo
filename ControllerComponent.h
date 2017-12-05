#ifndef CONTROLLER_COMPONENT_H
#define CONTROLER_COMPONENT_H

#include "EntityComponent.h"

#include <SFML/Window/Event.hpp>

class ControllerComponent : public EntityComponent
{
public:
	virtual void update(sf::Time delta) = 0;

	virtual void handleEvents(sf::Event& event, sf::Time delta) = 0;
	virtual void handleInputStates(sf::Time delta) = 0;

};

#endif