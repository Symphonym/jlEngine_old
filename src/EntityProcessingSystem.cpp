#include "EntityProcessingSystem.h"
#include "Component.h"
#include "Engine.h"
#include "Entity.h"

namespace jl
{
	EntityProcessingSystem::EntityProcessingSystem() : 
		m_enabled(true),
		m_engine(nullptr)
	{
		
	}


	void EntityProcessingSystem::addTargetComponent(Component *component)
	{
		m_targetComponents.insert(typeid(*component).hash_code());
	}
	void EntityProcessingSystem::removeTargetComponent(std::size_t hashCode)
	{
		auto itr = m_targetComponents.find(hashCode);
		if(itr != m_targetComponents.end())
			m_targetComponents.erase(itr);
	}
	void EntityProcessingSystem::removeTargetComponent(Component *component)
	{
		removeTargetComponent(typeid(*component).hash_code());
	}	
	bool EntityProcessingSystem::hasTargetComponent(Component *component) const
	{
		return m_targetComponents.find(typeid(*component).hash_code()) != m_targetComponents.end();
	}

	void EntityProcessingSystem::refreshEntity(Entity &entity)
	{
		// Iterate target components
		for(auto itr = m_targetComponents.begin(); itr != m_targetComponents.end(); itr++)
		{
			if(entity.getComponent(*itr) != nullptr)
				m_activeEntities[entity.getId()] = &entity;
			else
			{
				auto eraseItr = m_activeEntities.find(entity.getId());
				if(eraseItr != m_activeEntities.end())
					m_activeEntities.erase(eraseItr); 
			}
		}
	}

	void EntityProcessingSystem::setStatus(bool status)
	{
		m_engine->getSystemManager().setSystemStatus(this, status);
	}

	void EntityProcessingSystem::process()
	{
		if(isEnabled())
		{
			preProcess();
			for(auto itr = m_activeEntities.begin(); itr != m_activeEntities.end(); itr++)
			{
				if(itr->second->isEnabled())
				processEntity(*itr->second);
			}
			postProcess();
		}
	}

	bool EntityProcessingSystem::isEnabled() const
	{
		return m_enabled;
	}
};