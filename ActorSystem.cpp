#include "ActorSystem.h"
#include "EntityFactory.h"
#include "PlayerInput.h"
#include "InputEvent.h"

#include <iostream>

ActorSystem::ActorSystem()
{
	mDoesOneHaveControl = false;
}

ActorSystem::~ActorSystem()
{
	for (auto actor : mActors)
	{
		delete actor;
	}
	mActors.clear();
}

void ActorSystem::init(CollisionSystem& collisionSystem, const sf::Texture& texture, InputManager& inputManager)
{
	mInputManager = &inputManager;

	mInputManager->addObserver(this, InputManager::INPUT_TYPES::All);

	// initialize with 2 actors
	Entity* actor1 = EntityFactory::getEntity(Entity::ENTITY_TYPE::Player, texture);
	actor1->setPosition(400.f, 400.f);
	addControls(actor1);

	Entity* actor2 = EntityFactory::getEntity(Entity::ENTITY_TYPE::Player, texture);
	actor2->setPosition(400.f, 450.f);

	mActors.push_back(actor1);
	mActors.push_back(actor2);
}

void ActorSystem::onNotify(Event* event)
{
	std::cout << "Actor System notified!" << std::endl;

	switch (event->getEventType())
	{
	case Event::EVENT_TYPE::Input:
	{
		InputEvent* iEvent = dynamic_cast<InputEvent*>(event);

		switch (iEvent->mEvent.type)
		{
		case sf::Event::KeyPressed:
			if (iEvent->mEvent.key.code == sf::Keyboard::Space)
			{
				// toggle control
				removeControls(mActors[mDoesOneHaveControl]);
				mDoesOneHaveControl = !mDoesOneHaveControl;
				addControls(mActors[mDoesOneHaveControl]);
			}
		default:
			break;
		}
	}
	default:
		break;
	}
}

void ActorSystem::addControls(Entity* entity)
{
	InputComponent* inputComponent = new PlayerInput(entity);
	mInputManager->addObserver(inputComponent, InputManager::INPUT_TYPES::All);
	entity->attachComponent(inputComponent);
}

void ActorSystem::removeControls(Entity* entity)
{
	mInputManager->removeObserver(dynamic_cast<InputComponent*>(entity->getComponent(EntityComponent::COMPONENT_TYPE::Input)), InputManager::INPUT_TYPES::All);
	entity->detachComponent(EntityComponent::COMPONENT_TYPE::Input);
}


void ActorSystem::update(sf::Time deltaTime)
{
	for (auto actor : mActors)
	{
		actor->update(deltaTime);
	}
}

void ActorSystem::render(sf::RenderWindow& window, const RenderSystem& renderSystem)
{
	for (auto actor : mActors)
	{
		renderSystem.render(window, actor);
	}
}
