#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <deque>
#include <unordered_map>
#include <typeinfo>
#include "IdType.h"


namespace jl
{
	class Component;
	class Engine;
	class Entity;
	class EntityManager
	{
	private:

		// Simplify type used for Unique ID so it changed easily be
		// changed if neccesary.
		//typedef int IdType;

		IdType m_uniqueEntityId;
		IdType m_activeEntityCount; // Entities being actively processed

		// Queue for entities awaiting recycling (Allowing Entities to delete themselves)
		std::deque<IdType> m_entityRecycleQueue;

		std::unordered_map<IdType, Entity*> m_entities;
		// Entities available for recycling.
		std::vector<Entity*> m_removedAndAvailable;

		Engine *m_engine;

		void removeComponent(Entity &entity, std::size_t hashCode);
		Component* getComponent(Entity &entity, std::size_t hashCode);


	public:

		explicit EntityManager(Engine *engine);
		~EntityManager();

		// Allocates an entity on the heap and returns a reference to it.
		Entity& createEntity();

		// Asks for the entity at the front of the recycling queue, nullptr if queue is empty.
		// This function will not delete the Entity, it will solely return a pointer to it.
		Entity* nextEntityRecycle();
		// Immidiately deletes the next Entity marked for deletion. Returns false when the
		// queue is empty.
		bool issueEntityRecycle();

		// Marks an entity for recycling
		void recycleEntity(Entity &entity);
		void recycleEntity(IdType id);
		// Marks all active entities for recycling
		void recycleAllEntities();

		// Enables/Disables entity for processing by Systems
		void setEntityStatus(Entity &entity, bool status);

		// Strips entity of its components
		void stripEntity(IdType id);

		Entity& getEntity(IdType id);

		IdType getInactiveEntityCount() const;
		IdType getActiveEntityCount() const;
		IdType getRecyclableEntityCount() const;
		IdType getTotalEntityCount() const;

		std::size_t getRecycleQueueSize() const;
	};
};

#endif