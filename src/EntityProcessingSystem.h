#ifndef ENTITYPROCESSINGSYSTEM_H
#define ENTITYPROCESSINGSYSTEM_H

#include <unordered_set>
#include <unordered_map>
#include <typeinfo>
#include <string>

namespace jl
{
	class Component;
	class Engine;
	class Entity;
	class EntityProcessingSystem
	{
	private:

		friend class SystemManager;

		std::unordered_set<std::size_t> m_targetComponents; // Components the System operates on
		std::unordered_map<int, Entity*> m_activeEntities; // Entities being processed
		bool m_enabled;

		void removeTargetComponent(std::size_t hashCode);

	protected:
		EntityProcessingSystem();
		virtual ~EntityProcessingSystem(){};

		Engine *m_engine;

	public:

		void addTargetComponent(Component *component);
		template<typename T> void addTargetComponent()
		{
			m_targetComponents.insert(typeid(T).hash_code());
		};
		void removeTargetComponent(Component *component);
		template <typename T> void removeTargetComponent()
		{
			removeTargetComponent(typeid(T).hash_code());
		};
		
		bool hasTargetComponent(Component *component) const;
		template<typename T> bool hasTargetComponent() const
		{
			return m_targetComponents.find(typeid(T).hash_code()) != m_targetComponents.end();
		};

		void refreshEntity(Entity &entity);

		// Set whether or not the System is enabled
		void setStatus(bool status);

		// Iterates through all the compliant Entities and processes them
		// accordingly.
		void process();

		// These functions are run before/after Entities are
		// being processed by the System.
		virtual void preProcess(){};
		virtual void postProcess(){};
		virtual void processEntity(Entity &entity) = 0;

		bool isEnabled() const;

	};
};

#endif