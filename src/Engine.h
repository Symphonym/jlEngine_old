#ifndef JL_ENGINE_H
#define JL_ENGINE_H

#include "EntityManager.h"
#include "SystemManager.h"
#include "WindowManager.h"
#include "TagManager.h"
#include "GroupManager.h"

namespace jl
{
	class Entity;
	class EntityProcessingSystem;

	// Starting point of the Engine, the gameloop runs from here.
	class Engine
	{
	private:

		EntityManager m_entityManager;
		SystemManager m_systemManager;
		WindowManager m_windowManager;
		TagManager m_tagManager;
		GroupManager m_groupManager;
		// StateManager m_stateManager;
		// SceneManager m_sceneManager;

		// Whether the Engine is running or not
		bool m_running;
		double m_deltaTime;
		std::size_t m_fps;
		
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
		TagManager& getTagManager();
		GroupManager& getGroupManager();
	};
};

#endif