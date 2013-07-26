#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <unordered_map>
#include <typeinfo>

namespace jl
{
	class Engine;
	class Entity;
	class EntityProcessingSystem;
	class SystemManager
	{
	private:

		typedef std::unordered_map<std::size_t, EntityProcessingSystem*> SystemBag;
		int m_activeSystemCount;

		SystemBag m_systems;
		Engine *m_engine;


	public:

		explicit SystemManager(Engine *engine);
		~SystemManager();

		void addSystem(EntityProcessingSystem *system);
		void removeSystem(EntityProcessingSystem *system);
		template<typename T> void removeSystem()
		{
			removeSystem(getSystem<T>());
		};

		void setSystemStatus(EntityProcessingSystem *system, bool status);
		template<typename T> void setSystemStatus(bool status)
		{
			EntityProcessingSystem *system = getSystem<T>();
			if(system != nullptr)
				setSystemStatus(system, status);
		};

		// Iterating through all enabled Systems and process their entities
		void processSystems();

		// Refreshes the Systems with the specified Entity, checking
		// if it has one of it's targeted components.
		bool refreshEntity(Entity &entity);

		template<typename T> T* getSystem()
		{
			auto itr = m_systems.find(typeid(T).hash_code());
			return itr != m_systems.end() ? static_cast<T*>(itr->second) : nullptr;
		};
		const SystemBag getAllSystems() const;
		std::size_t getTotalSystemCount() const;
		std::size_t getActiveSystemCount() const;
		std::size_t getInactiveSystemCount() const;
	};
};

#endif