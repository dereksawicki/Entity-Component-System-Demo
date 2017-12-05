#ifndef COMMAND_H
#define COMMAND_H

#include "EntityComponent.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(EntityComponent& entityComponent) = 0;
};

#endif