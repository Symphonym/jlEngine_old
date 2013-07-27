#include "TagManager.h"
#include "Entity.h"
#include <vector>

namespace jl
{
	void TagManager::tagEntity(Entity &entity, const std::string &name)
	{
		m_taggedEntities[name] = &entity;
		
	}

	void TagManager::untagEntity(Entity &entity)
	{
		std::vector<std::string> associatedTags;
		for(auto itr = m_taggedEntities.begin(); itr != m_taggedEntities.end(); itr++)
		{
			if(itr->second != nullptr)
			{
				if(itr->second->getId() == entity.getId())
					associatedTags.push_back(itr->first);
			}
		}
		for(int i = 0; i < associatedTags.size(); i++)
			m_taggedEntities.erase(associatedTags[i]);
	}
	void TagManager::untagEntity(const std::string &name)
	{
		auto itr = m_taggedEntities.find(name);
		if(itr != m_taggedEntities.end())
			m_taggedEntities.erase(itr);
	}

	bool TagManager::isTagged(const std::string &name) const
	{
		return m_taggedEntities.find(name) != m_taggedEntities.end();
	}

	Entity& TagManager::getEntity(const std::string &name)
	{
		return *m_taggedEntities[name];
	}
};