#ifndef ENGINE_H
#define ENGINE_H

#include "EntityManager.h"
#include "SystemManager.h"
#include "WindowManager.h"

namespace jl
{
	class Entity;
	class EntityProcessingSystem;
	class Engine
	{
	private:

		EntityManager m_entityManager;
		SystemManager m_systemManager;
		WindowManager m_windowManager;
		// StateManager m_stateManager;
		// SceneManager m_sceneManager;

		// Whether the Engine is running or not
		bool m_running;

		
		void gameLoop();

	public:

		Engine();

		// run(State *startState);
		void stop();

		// void push

		std::size_t getFps() const;
		float getDelta() const;

		EntityManager& getEntityManager();
		SystemManager& getSystemManager();
		WindowManager& getWindowManager();
	};
};

#endif