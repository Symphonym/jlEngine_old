#ifndef GROUPMANAGER_H
#define GROUPMANAGER_H

#include <unordered_map>
#include <unordered_set>
#include "IdType.h"

namespace jl
{
	class GroupManager
	{
	private:

		// TODO GroupManager

		std::unordered_map<std::string, std::unordered_map<IdType, Entity*> m_entitiesByGroup;
		std::unordered_map<IdType, std::unordered_set<std::string> > m_groupsByEntity;

	public:

		// Add the Entity to the specified group.
		void addToGroup(Entity &entity, const std::string &group);
		// Remove the Entity from the specified group.
		void removeFromGroup(Entity &entity, const std::string &group);
		// Remove the Entity from all groups it's located in.
		void removeFromGroups(Entity &entity);

		// Returns whether or not the Entity is in the specified group
		bool isInGroup(const Entity &entity, const std::string &group) const;


	};
};

#endif