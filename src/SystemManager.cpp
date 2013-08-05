#include "SystemManager.h"
#include "Component.h"
#include "Entity.h"
#include "System.h"
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
		m_systems.clear();
	}

	void SystemManager::addSystem(System *system)
	{
		const std::type_info &typeinfo = typeid(*system);
		if(system != m_systems[typeinfo].get())
			removeSystem(system);

		system->m_engine = m_engine;
		m_systems[typeinfo] = SystemPtr(system);

	}
	void SystemManager::removeSystem(System *system)
	{
		auto itr = m_systems.find(typeid(*system));
		if(itr != m_systems.end())
			m_systems.erase(itr);
	}

	void SystemManager::setSystemStatus(System *system, bool status)
	{
		if(system->isEnabled() != status)
			m_activeSystemCount += status ? 1 : -1;

		system->m_enabled = status;
	}

	bool SystemManager::refreshEntity(Entity &entity)
	{
		// Iterate systems and refreshEntity
		for(auto sItr = m_systems.begin(); sItr != m_systems.end(); sItr++)
			sItr->second->refreshEntity(entity);
	}

	const SystemManager::SystemBag& SystemManager::getAllSystems() const
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