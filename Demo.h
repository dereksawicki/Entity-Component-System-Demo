#ifndef DEMO_H
#define DEMO_H

//#include "Audio.h"
//#include "EventQueue.h"
#include "RenderSystem.h"
#include "CollisionSystem.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

class Demo
{
public:
	Demo();

	void run();

private:
	//void update();
	void render();

private:
	Entity* mPlayer;
	Entity* mToggleSuitPickup;

	RenderSystem mRenderSystem;
	CollisionSystem mCollisionSystem;
	//EventQueue mEventQueue;
	//Audio mAudio;

	sf::RenderWindow mWindow;
	sf::Texture mSpriteSheet;
};


#endif