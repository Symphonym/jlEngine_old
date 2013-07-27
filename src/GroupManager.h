#ifndef GROUPMANAGER_H
#define GROUPMANAGER_H

#include "IdType.h"

namespace jl
{
	class GroupManager
	{
	private:

		// TODO GroupManager

		//std::unordered_map<std::string, std::vector<Entity*> > m_entitiesByGroup;
		//std::unordered_map<

	public:

		void addToGroup(const std::string &group, Entity &entity);
		void removeFromGroup(const std::string &group, Entity &entity);
		void removeFromGroups(Entity &entity);


	};
};

#endif