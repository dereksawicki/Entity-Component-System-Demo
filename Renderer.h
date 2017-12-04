#ifndef RENDERER_H
#define RENDERER_H


#include "Entity.h"

#include <SFML/Graphics/RenderWindow.hpp>

class Renderer
{
public:
	static void render(sf::RenderWindow& window, Entity* entity);

};

#endif