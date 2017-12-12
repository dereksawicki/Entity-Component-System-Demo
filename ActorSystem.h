#ifndef ACTOR_SYSTEM_H
#define ACTOR_SYSTEM_H

#include "Entity.h"
#include "InputManager.h"
#include "InputComponent.h"
#include "RenderSystem.h"
#include "CollisionSystem.h"
#include "Observer.h"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <vector>

class ActorSystem : public Observer
{
public:
	ActorSystem();
	~ActorSystem();

	void init(CollisionSystem& collisionSystem, const sf::Texture& texture, InputManager& inputManager);

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow& window, const RenderSystem& renderSystem);

	virtual void onNotify(Event* event);

	const std::vector<Entity*>& getActors() { return mActors; };

private:
	void addControls(Entity* entity);
	void removeControls(Entity* entity);

private:
	std::vector<Entity*> mActors;
	InputManager* mInputManager;
	bool mDoesOneHaveControl;

};


#endif