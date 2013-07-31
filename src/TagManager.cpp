#include "TagManager.h"
#include "Entity.h"

namespace jl
{

	void TagManager::tagEntity(Entity &entity, const std::string &name)
	{
		untagEntity(name);

		m_entityByTag[name] = &entity;
		m_tagByEntity[entity.getId()] = name;
	}

	void TagManager::untagEntity(const Entity &entity)
	{
		auto itr = m_tagByEntity.find(entity.getId());
		if(itr != m_tagByEntity.end())
		{
			m_entityByTag.erase(itr->second);
			m_tagByEntity.erase(itr);
		}
	}
	void TagManager::untagEntity(const std::string &name)
	{
		auto itr = m_entityByTag.find(name);
		if(itr != m_entityByTag.end())
		{
			m_entityByTag.erase(itr);
			m_tagByEntity.erase(itr->second->getId());
		}
	}

	bool TagManager::isTagged(const std::string &name) const
	{
		return m_entityByTag.find(name) != m_entityByTag.end();
	}
	bool TagManager::isTagged(const Entity &entity) const
	{
		return m_tagByEntity.find(entity.getId()) != m_tagByEntity.end();
	}
	bool TagManager::isTaggedTo(const Entity &entity, const std::string &name) const
	{
		auto itr = m_tagByEntity.find(entity.getId());
		return itr != m_tagByEntity.end() ? (itr->second == name) : false;
	}

	Entity& TagManager::getEntity(const std::string &name)
	{
		return *m_entityByTag.at(name);
	}
};