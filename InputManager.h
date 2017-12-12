#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "Subject.h"

#include <SFML/Graphics/RenderWindow.hpp>

class InputManager : public Subject
{
public:
	enum INPUT_TYPES 
	{
		None
	  , All
	};

public:
	void pollEvents(sf::RenderWindow& window);
};

#endif