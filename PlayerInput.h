#ifndef PLAYER_INPUT_H
#define PLAYER_INPUT_H

#include "InputComponent.h"

/* Player input = use WASD to move entity */
class PlayerInput : public InputComponent
{
public:
	PlayerInput(Entity* parent);

	virtual void update(sf::Time deltaTime);
	virtual void onNotify(Event* event);
private:
	Entity* mParent;
};


#endif