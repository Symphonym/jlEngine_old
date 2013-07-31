#ifndef GROUPMANAGER_H
#define GROUPMANAGER_H

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

		std::unordered_map<std::string, std::unordered_map<IdType, Entity*> > m_entitiesByGroup;
		std::unordered_map<IdType, std::unordered_set<std::string> > m_groupsByEntity;

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
		const std::unordered_set<std::string>& getGroupsOf(const Entity &entity) const;
		std::unordered_map<IdType, Entity*>& getGroup(const std::string &name);



	};
};

#endif