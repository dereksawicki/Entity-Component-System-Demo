#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H


#include "Entity.h"

#include <SFML/Graphics/RenderWindow.hpp>

class RenderSystem
{
public:
	static void render(sf::RenderWindow& window, Entity* entity);

};

#endif