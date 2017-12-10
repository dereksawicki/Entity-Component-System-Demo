#ifndef DEMO_H
#define DEMO_H

//#include "Audio.h"
//#include "EventQueue.h"
#include "RenderSystem.h"
#include "CollisionSystem.h"
#include "PickupSystem.h"

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

	RenderSystem mRenderSystem;
	CollisionSystem mCollisionSystem;
	PickupSystem mPickupSystem;

	//EventQueue mEventQueue;
	//Audio mAudio;

	sf::RenderWindow mWindow;
	sf::Texture mSpriteSheet;
};


#endif