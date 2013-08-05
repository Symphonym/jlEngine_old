#include "EntityManager.h"
#include "Entity.h"
#include "Component.h"
#include <typeinfo>

namespace jl
{
	EntityManager::EntityManager(Engine *engine) :
		m_uniqueEntityId(0),
		m_activeEntityCount(0),
		m_engine(engine)
	{

	}
	EntityManager::~EntityManager()
	{
		m_removedAndAvailable.clear();
		m_entities.clear();
		m_entityRecycleQueue.clear();
	}

	Entity& EntityManager::createEntity()
	{
		// Retrieve recycled Entity or allocate a new one if there's no
		// recycled entities available
		EntityPtr entity = !m_removedAndAvailable.empty() ? 
			std::move(m_removedAndAvailable.back()) : 
			EntityPtr(new Entity(m_engine, m_uniqueEntityId++));

		if(!m_removedAndAvailable.empty())
			m_removedAndAvailable.pop_back();

		// So we have something to return, seeing how the Entity gets
		// moved before we reach the return statement.
		Entity *entityPtr = entity.get();

		entity->setStatus(true);
		m_entities[entity->getId()] = std::move(entity);

		return *entityPtr;
	}

	Entity* EntityManager::nextEntityRecycle()
	{
		return !m_entityRecycleQueue.empty() ? m_entities[m_entityRecycleQueue.front()].get() : nullptr;
	}
	bool EntityManager::issueEntityRecycle()
	{

		if(m_entityRecycleQueue.empty())
			return false;

		EntityPtr& entity = m_entities.at(m_entityRecycleQueue.front());

		stripEntity(m_entityRecycleQueue.front());
		entity->setStatus(false);
		entity->refresh();

		// Move Entity to recycle stack
		m_removedAndAvailable.push_back(std::move(entity));

		m_entities.erase(m_entityRecycleQueue.front());
		m_entityRecycleQueue.pop_front();

		return true;
	}

	void EntityManager::recycleEntity(Entity &entity)
	{
		m_entityRecycleQueue.push_back(entity.getId());
	}
	void EntityManager::recycleEntity(IdType id)
	{
		m_entityRecycleQueue.push_back(id);
	}
	void EntityManager::recycleAllEntities()
	{
		for(auto& itr : m_entities)
			recycleEntity(itr.first);
	}

	void EntityManager::setEntityStatus(Entity &entity, bool status)
	{
		if(entity.isEnabled() != status)
			m_activeEntityCount += status ? 1 : -1;

		entity.m_enabled = status;
	}

	void EntityManager::stripEntity(IdType id)
	{
		getEntity(id).removeAllComponents();
	}

	Entity& EntityManager::getEntity(IdType id)
	{
		return *m_entities.at(id);
	}

	IdType EntityManager::getInactiveEntityCount() const
	{
		return m_entities.size() - m_activeEntityCount;
	}
	IdType EntityManager::getActiveEntityCount() const
	{
		return m_activeEntityCount;
	}
	IdType EntityManager::getRecyclableEntityCount() const
	{
		return m_removedAndAvailable.size();
	}
	IdType EntityManager::getTotalEntityCount() const
	{
		return m_removedAndAvailable.size() + m_entities.size();
	}

	std::size_t EntityManager::getRecycleQueueSize() const
	{
		return m_entityRecycleQueue.size();
	}
};