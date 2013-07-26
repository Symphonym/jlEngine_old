#include "SystemManager.h"
#include "Component.h"
#include "Entity.h"
#include "EntityProcessingSystem.h"
#include <iostream>

namespace jl
{
	SystemManager::SystemManager(Engine *engine) :
		m_activeSystemCount(0),
		m_engine(engine)
	{

	}
	SystemManager::~SystemManager()
	{
		for(auto itr = m_systems.begin(); itr != m_systems.end(); itr++)
		{
			delete itr->second;
			itr->second = nullptr;
		}
		m_systems.clear();
	}

	void SystemManager::addSystem(EntityProcessingSystem *system)
	{
		std::size_t hashCode = typeid(*system).hash_code();
		if(system != m_systems[hashCode])
			removeSystem(system);

		system->m_engine = m_engine;
		m_systems[hashCode] = system;

	}
	void SystemManager::removeSystem(EntityProcessingSystem *system)
	{
		auto itr = m_systems.find(typeid(*system).hash_code());
		if(itr != m_systems.end())
		{
			delete itr->second;
			m_systems.erase(itr);
		}
	}

	void SystemManager::setSystemStatus(EntityProcessingSystem *system, bool status)
	{
		m_activeSystemCount += status ? 1 : -1;
		system->m_enabled = status;
	}

	bool SystemManager::refreshEntity(Entity &entity)
	{
		// Iterate systems and refreshEntity
		for(auto sItr = m_systems.begin(); sItr != m_systems.end(); sItr++)
			sItr->second->refreshEntity(entity);
	}

	const SystemManager::SystemBag SystemManager::getAllSystems() const
	{
		return m_systems;
	}

	std::size_t SystemManager::getTotalSystemCount() const
	{
		return m_systems.size();
	}
	std::size_t SystemManager::getActiveSystemCount() const
	{
		return m_activeSystemCount;
	}
	std::size_t SystemManager::getInactiveSystemCount() const
	{
		return m_systems.size() - m_activeSystemCount;
	}
};