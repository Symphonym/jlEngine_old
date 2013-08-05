#include "GroupManager.h"
#include "Entity.h"

namespace jl
{
	void GroupManager::addToGroup(Entity &entity, const std::string &group)
	{
		m_groupsByEntity[entity.getId()].insert(group);
		m_entitiesByGroup[group][entity.getId()] = &entity;
	}
	void GroupManager::removeFromGroup(Entity &entity, const std::string &group)
	{
		// TODO Optimize this somehow


		// Get list of groups that the Entity is in
		auto groupListItr = m_groupsByEntity.find(entity.getId());
		if(groupListItr != m_groupsByEntity.end())
		{
			// Check if the specified group can be found
			auto groupNameItr = groupListItr->second.find(group);
			if(groupNameItr != groupListItr->second.end())
			{
				// Erase from group set
				groupListItr->second.erase(groupNameItr);

				// Make sure the group actually exists
				auto groupItr = m_entitiesByGroup.find(group);
				if(groupItr != m_entitiesByGroup.end())
				{
					// Erase Entity from the group
					auto entityItr = groupItr->second.find(entity.getId());
					if(entityItr != groupItr->second.end())
						groupItr->second.erase(entityItr);
				}

				// Erase from Entity map
				m_entitiesByGroup[group].erase(entity.getId());

				// Completely remove group if it's empty
				if(groupListItr->second.empty())
					m_groupsByEntity.erase(groupListItr);
				if(groupItr->second.empty())
					m_entitiesByGroup.erase(groupItr);
			}
		}
	}
	void GroupManager::removeFromGroups(Entity &entity)
	{
		auto groupListItr = m_groupsByEntity.find(entity.getId());
		if(groupListItr != m_groupsByEntity.end())
		{
			auto itr = groupListItr->second.begin();
			while(itr != groupListItr->second.end())
				removeFromGroup(entity, *itr++);
		}
	}

	bool GroupManager::isInGroup(const Entity &entity, const std::string &group) const
	{
		auto itr = m_groupsByEntity.find(entity.getId());
		return itr != m_groupsByEntity.end() ? (itr->second.find(group) != itr->second.end()) : false;
	}
	bool GroupManager::isGroupExisting(const std::string &name) const
	{
		return m_entitiesByGroup.find(name) != m_entitiesByGroup.end();
	}


	const GroupManager::GroupList& GroupManager::getGroupsOf(const Entity &entity) const
	{
		auto itr = m_groupsByEntity.find(entity.getId());
		return itr != m_groupsByEntity.end() ? itr->second : empty_grouplist;
	}	
	GroupManager::Group& GroupManager::getGroup(const std::string &name)
	{
		return m_entitiesByGroup.at(name);
	}
};