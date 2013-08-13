#include "Engine.h"
#include "Screen.h"
#include <SFML/System.hpp>

namespace jl
{
	Engine::Engine() :
		m_entityManager(this),
		m_systemManager(this),
		m_screenManager(this),
		m_running(true),
		m_deltaTime(0),
		m_fps(0)
	{

	}

	void Engine::gameLoop()
	{
		sf::Clock deltaClock, fpsClock;

		sf::Event windowEvent;
		while(m_running)
		{

			// Get FPS and deltaTime
			m_deltaTime = deltaClock.restart().asSeconds();
			if(fpsClock.getElapsedTime().asSeconds() > 1)
			{
				m_fps = 1.0 / m_deltaTime;
				fpsClock.restart();
			}

			// Remove entities from all the related managers
			Entity* removedEntity = m_entityManager.nextEntityRecycle();
			while(removedEntity != nullptr)
			{
				// Remove entity elsewhere
				m_tagManager.untagEntity(*removedEntity);
				m_groupManager.removeFromGroups(*removedEntity);

				m_entityManager.issueEntityRecycle();
				removedEntity = m_entityManager.nextEntityRecycle();
			}

			// Handle all requests to delete Screens
			m_screenManager.issueDeleteRequests();

			// Engine halts when the state machine is empty
			if(m_screenManager.isEmpty())
			{
				stop();
				break;
			}

			// Iterate through Screens and the ones below depending on transparency			
			while(m_window.pollEvent(windowEvent))
			{
				if(windowEvent.type == sf::Event::Closed)
					m_window.close();

				for(int i = 0; i < m_screenManager.getStack().size(); i++)
				{
					std::size_t indexAbove = i + 1;
					if((indexAbove < m_screenManager.getStack().size() && m_screenManager.getStack()[indexAbove]->isEventTransparent()) ||
						indexAbove >= m_screenManager.getStack().size()) // Top-most Screen, will naturally get called
						m_screenManager.getStack()[i]->events(windowEvent);
				}
			}
			for(int i = 0; i < m_screenManager.getStack().size(); i++)
			{
				std::size_t indexAbove = i + 1;
				if((indexAbove < m_screenManager.getStack().size() && m_screenManager.getStack()[indexAbove]->isUpdateTransparent()) ||
					indexAbove >= m_screenManager.getStack().size()) // Top-most Screen, will naturally get called
					m_screenManager.getStack()[i]->update(m_deltaTime);

				if((indexAbove < m_screenManager.getStack().size() && m_screenManager.getStack()[indexAbove]->isDrawTransparent()) ||
					indexAbove >= m_screenManager.getStack().size()) // Top-most Screen, will naturally get called
					m_screenManager.getStack()[i]->draw();
			}

			m_window.display();
		}
	}

	void Engine::stop()
	{
		m_running = false;
	}


	void Engine::createWindow(sf::VideoMode &mode, const sf::String &title, sf::Uint32 style, const sf::ContextSettings& context)
	{
		m_window.create(mode, title, style, context);
	}

	void Engine::setWindowTitle(const std::string &name)
	{
		m_window.setTitle(name);
	}
	void Engine::setWindowSize(std::size_t width, std::size_t height)
	{
		m_window.setSize(sf::Vector2u(width, height));
	}

	sf::Vector2i Engine::getWindowPosition() const
	{
		return m_window.getPosition();
	}
	sf::Vector2u Engine::getWindowSize() const
	{
		return m_window.getSize();
	}
	const sf::ContextSettings& Engine::getWindowContext() const
	{
		return m_window.getSettings();
	}

	std::size_t Engine::getFps() const
	{
		return m_fps;
	}
	float Engine::getDelta() const
	{
		return m_deltaTime;
	}

	sf::Window& Engine::getWindow()
	{
		return m_window;
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
	ScreenManager& Engine::getScreenManager()
	{
		return m_screenManager;
	}
};