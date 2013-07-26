#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "EntityProcessingSystem.h"
#include "ComponentMapper.h"
#include "InputComponent.h"

class InputSystem : public jl::EntityProcessingSystem
{
public:

	InputSystem()
	{
		addTargetComponent<InputComponent>();
	};

	virtual void processEntity(jl::Entity &entity)
	{
		jl::ComponentMapper<InputComponent> input;
		input(entity)->x = 1337;
	};
};

#endif