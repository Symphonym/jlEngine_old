#ifndef TAGMANAGER_H
#define TAGMANAGER_H

#include <unordered_map>
#include <string>
#include "IdType.h"

namespace jl
{
	class Entity;
	class TagManager
	{
	private:

		std::unordered_map<std::string, Entity*> m_entityByTag;
		std::unordered_map<IdType, std::string> m_tagByEntity;

	public:

		void tagEntity(Entity &entity, const std::string &name);

		// Removes the tag associated with the specified Entity
		void untagEntity(Entity &entity);
		// Removes the specified tag
		void untagEntity(const std::string &name);

		// Returns whether or not the specified name has been tagged to an Entity
		bool isTagged(const std::string &name) const;
		// Returns whether or not the specified Entity has been tagged
		bool isTagged(const Entity &entity) const;
		// Returns whether or not the specified Entity has been tagged to
		// the specified name.
		bool isTaggedTo(const Entity &entity, const std::string &name) const;

		Entity& getEntity(const std::string &name);
	};
};

#endif