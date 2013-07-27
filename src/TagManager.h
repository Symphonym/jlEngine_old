#ifndef TAGMANAGER_H
#define TAGMANAGER_H

#include <unordered_map>
#include <string>

namespace jl
{
	class Entity;
	class TagManager
	{
	private:

		std::unordered_map<std::string, Entity*> m_taggedEntities;

	public:

		void tagEntity(Entity &entity, const std::string &name);

		// Removes all tags associated with the specified Entity
		void untagEntity(Entity &entity);
		// Removes the specified tag
		void untagEntity(const std::string &name);

		// Returns whether or not the specified name has been tagged to an Entity
		bool isTagged(const std::string &name) const;

		Entity& getEntity(const std::string &name);
	};
};

#endif