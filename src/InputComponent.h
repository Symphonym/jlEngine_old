#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "Component.h"

class InputComponent : public jl::Component
{
public:
	int x, y;

	virtual std::string getName() const
	{return "InputComponent";};
};

#endif