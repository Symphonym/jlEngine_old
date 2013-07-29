#include "Engine.h"

namespace jl
{
	Engine::Engine() :
		m_entityManager(this),
		m_systemManager(this),
		m_running(true)
	{

	}

	void Engine::gameLoop()
	{
		while(m_running)
		{
			Entity* removedEntity = m_entityManager.nextEntityRecycle();
			while(removedEntity != nullptr)
			{
				// Remove entity elsewhere
				m_tagManager.untagEntity(*removedEntity);

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
		return 0;
	}
	float Engine::getDelta() const
	{
		return 0;
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
};