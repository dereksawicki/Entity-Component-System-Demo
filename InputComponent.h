#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include "Observer.h"
#include "EntityComponent.h"
#include "Entity.h"

class InputComponent : public EntityComponent, public Observer
{
public:
	enum INPUT_TYPE {
		None
	  , Player
	};

public:
	virtual void update(sf::Time deltaTime) {}
	virtual void onNotify(Event* event) {}
	INPUT_TYPE getInputType() { return mInputType; }

protected:

	Entity* mParent;
	INPUT_TYPE mInputType;
};

#endif