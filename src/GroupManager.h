#ifndef JL_GROUPMANAGER_H
#define JL_GROUPMANAGER_H

#include <unordered_map>
#include <unordered_set>
#include <string>
#include "IdType.h"

namespace jl
{
	class Entity;
	class GroupManager
	{
	private:

		typedef std::unordered_map<IdType, Entity*> Group;
		typedef std::unordered_set<std::string> GroupList;

		std::unordered_map<std::string, Group> m_entitiesByGroup;
		std::unordered_map<IdType, GroupList> m_groupsByEntity;

		// Empty list of groups that is referenced when an Entity is located in zero(0) groups
		const std::unordered_set<std::string> empty_grouplist;

	public:

		// Add the Entity to the specified group.
		void addToGroup(Entity &entity, const std::string &group);
		// Remove the Entity from the specified group.
		void removeFromGroup(Entity &entity, const std::string &group);
		// Remove the Entity from all groups it's located in.
		void removeFromGroups(Entity &entity);

		// Returns whether or not the Entity is in the specified group
		bool isInGroup(const Entity &entity, const std::string &group) const;
		bool isGroupExisting(const std::string &group) const;

		// Returns all the groups that the Entity is located in
		const GroupList& getGroupsOf(const Entity &entity) const;
		Group& getGroup(const std::string &name);



	};
};

#endif