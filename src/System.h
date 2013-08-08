#ifndef JL_SYSTEM_H
#define JL_SYSTEM_H

#include <unordered_set>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <string>

namespace jl
{
	class Component;
	class Engine;
	class Entity;
	class System
	{
	private:

		friend class SystemManager;

		std::unordered_set<std::type_index> m_targetComponents; // Components the System operates on
		std::unordered_map<int, Entity*> m_activeEntities; // Entities being processed
		bool m_enabled;

		void removeTargetComponent(const std::type_index &typeindex);

	protected:
		System();

		Engine *m_engine;

	public:

		virtual ~System(){};

		void addTargetComponent(Component *component);
		template<typename T> void addTargetComponent()
		{
			m_targetComponents.insert(typeid(T));
		};
		void removeTargetComponent(Component *component);
		template <typename T> void removeTargetComponent()
		{
			removeTargetComponent(typeid(T));
		};
		
		bool hasTargetComponent(Component *component) const;
		template<typename T> bool hasTargetComponent() const
		{
			return m_targetComponents.find(typeid(T)) != m_targetComponents.end();
		};

		void refreshEntity(Entity &entity);

		// Set whether or not the System is enabled
		void setStatus(bool status);

		// Iterates through all the compliant Entities and processes them
		// accordingly.
		void process();

		virtual void preProcess(){};
		virtual void postProcess(){};
		virtual void processEntity(Entity &entity) = 0;

		bool isEnabled() const;

		// Returns the number of Entities currently being
		// processed by the System
		std::size_t getActiveEntityCount() const;

	};
};

#endif