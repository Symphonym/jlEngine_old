#include "EntityManager.h"
#include "Entity.h"
#include "Component.h"

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
		for(auto itr = m_entities.begin(); itr != m_entities.end(); itr++)
			m_removedAndAvailable.push_back(itr->second);

		for(int i = 0; i < m_removedAndAvailable.size(); i++)
		{
			Entity* entity = m_removedAndAvailable[i];
			if(entity != nullptr)
			{
				delete entity;
				entity = nullptr;
			}
		}

		m_removedAndAvailable.clear();
		m_entities.clear();
		m_entityRecycleQueue.clear();
	}

	Entity& EntityManager::createEntity()
	{
		Entity* entity = !m_removedAndAvailable.empty() ? 
			m_removedAndAvailable.back() : 
			new Entity(m_engine, m_uniqueEntityId++);

		if(!m_removedAndAvailable.empty())
			m_removedAndAvailable.pop_back();

		m_entities[entity->getId()] = entity;
		++m_activeEntityCount;

		return *entity;
	}



	Entity* EntityManager::nextEntityRecycle()
	{
		return !m_entityRecycleQueue.empty() ? m_entities[m_entityRecycleQueue.front()] : nullptr;
	}
	bool EntityManager::issueEntityRecycle()
	{

		if(m_entityRecycleQueue.empty())
			return false;

		Entity& entity = getEntity(m_entityRecycleQueue.front());

		if(entity.isEnabled())
			--m_activeEntityCount;
		
		stripEntity(entity.getId());
		entity.refresh();

		// Move Entity to recycle stack
		m_removedAndAvailable.push_back(&entity);

		m_entities.erase(entity.getId());

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
		for(auto itr = m_entities.begin(); itr != m_entities.end(); itr++)
			recycleEntity(itr->first);
	}

	void EntityManager::setEntityStatus(Entity &entity, bool enabled)
	{
		entity.m_enabled = enabled;
		m_activeEntityCount += enabled ? 1 : -1;
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