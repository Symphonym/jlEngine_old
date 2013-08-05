#ifndef JL_SYSTEMMANAGER_H
#define JL_SYSTEMMANAGER_H

#include <unordered_map>
#include <typeindex>
#include <memory>

namespace jl
{
	class Engine;
	class Entity;
	class System;
	class SystemManager
	{
	private:

		typedef std::unique_ptr<System> SystemPtr;
		typedef std::unordered_map<std::type_index, SystemPtr> SystemBag;
		int m_activeSystemCount;

		SystemBag m_systems;
		Engine *m_engine;


	public:

		explicit SystemManager(Engine *engine);
		~SystemManager();

		// TODO possibly return pointer to system to make it more user-friendly
		void addSystem(System *system);
		void removeSystem(System *system);
		template<typename T> void removeSystem()
		{
			removeSystem(getSystem<T>());
		};

		void setSystemStatus(System *system, bool status);
		template<typename T> void setSystemStatus(bool status)
		{
			T *system = getSystem<T>();
			if(system != nullptr)
				setSystemStatus(system, status);
		};

		// Refreshes the Systems with the specified Entity, checking
		// if it has one of it's targeted components.
		bool refreshEntity(Entity &entity);

		template<typename T> T* getSystem()
		{
			auto itr = m_systems.find(typeid(T));
			return itr != m_systems.end() ? static_cast<T*>(itr->second.get()) : nullptr;
		};
		
		const SystemBag& getAllSystems() const;
		std::size_t getTotalSystemCount() const;
		std::size_t getActiveSystemCount() const;
		std::size_t getInactiveSystemCount() const;
	};
};

#endif