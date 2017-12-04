#ifndef DEMO_H
#define DEMO_H

//#include "Audio.h"
//#include "EventQueue.h"
#include "Renderer.h"

#include <SFML/Graphics/RenderWindow.hpp>

class Demo
{
public:
	Demo();

	void run();

private:
	//void update();
	void render();

private:
	Entity* player;
	Renderer renderer;
	//EventQueue mEventQueue;
	//Audio mAudio;

	sf::RenderWindow mWindow;
};


#endif