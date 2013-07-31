#include "Engine.h"
#include <SFML/System.hpp>

namespace jl
{
	Engine::Engine() :
		m_entityManager(this),
		m_systemManager(this),
		m_running(true),
		m_deltaTime(0),
		m_fps(0)
	{

	}

	void Engine::gameLoop()
	{
		sf::Clock deltaClock, fpsClock;

		while(m_running)
		{

			m_deltaTime = deltaClock.restart().asSeconds();
			if(fpsClock.getElapsedTime().asSeconds() > 1)
			{
				m_fps = 1.0 / m_deltaTime;
				fpsClock.restart();
			}

			Entity* removedEntity = m_entityManager.nextEntityRecycle();
			while(removedEntity != nullptr)
			{
				// Remove entity elsewhere
				m_tagManager.untagEntity(*removedEntity);
				m_groupManager.removeFromGroups(*removedEntity);

				m_entityManager.issueEntityRecycle();
				removedEntity = m_entityManager.nextEntityRecycle();
			}
		}
	}

	void Engine::stop()
	{
		m_running = false;
	}

	std::size_t Engine::getFps() const
	{
		return m_fps;
	}
	float Engine::getDelta() const
	{
		return m_deltaTime;
	}

	EntityManager& Engine::getEntityManager()
	{
		return m_entityManager;
	}
	SystemManager& Engine::getSystemManager()
	{
		return m_systemManager;
	}
	WindowManager& Engine::getWindowManager()
	{
		return m_windowManager;
	}
	TagManager& Engine::getTagManager()
	{
		return m_tagManager;
	}
	GroupManager& Engine::getGroupManager()
	{
		return m_groupManager;
	}
};