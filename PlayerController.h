#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "InputController.h"
#include "Entity.h"

class PlayerController : public InputController
{
public:

private:
	Entity* mEntity;
};


#endif