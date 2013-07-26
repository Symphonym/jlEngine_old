#ifndef COMPONENTMAPPER_H
#define COMPONENTMAPPER_H

#include <string>
#include "Entity.h"

namespace jl
{
	template<typename T> class ComponentMapper
	{
	public:

		// Checks whether or not the component exists within the Entity
		bool exists(Entity &entity)
		{
			return entity.getComponent<T>() != nullptr;
		};

		// Returns the component stored by the specified name within
		// the Entity. If the no component was found, nullptr is returned.
		T* get(Entity &entity)
		{
			return entity.getComponent<T>();
		};
		T* operator()(Entity &entity)
		{
			return get(entity);
		};
	};
};

#endif