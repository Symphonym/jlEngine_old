#ifndef JL_ENGINE_H
#define JL_ENGINE_H

#include "EntityManager.h"
#include "SystemManager.h"
#include "WindowManager.h"
#include "TagManager.h"
#include "GroupManager.h"
#include "ScreenManager.h"
#include <SFML/Window.hpp>

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
		ScreenManager m_screenManager;
		// SceneManager m_sceneManager;

		// TODO single window looped in gameloop
		// get rid of the windowmanager and haf fun

		// Main game window
		sf::Window m_window;

		// Whether the Engine is running or not
		bool m_running;
		double m_deltaTime;
		std::size_t m_fps;

		void gameLoop();

	public:

		Engine();

		// run(State *startState);
		void stop();

		// Creates, or recreates the game window with the specified data
		void createWindow(
			sf::VideoMode &mode,
			const sf::String &title,
			sf::Uint32 style = sf::Style::Default,
			const sf::ContextSettings& context = sf::ContextSettings());

		// Set title of the window, as displayed at the top of the window
		void setWindowTitle(const std::string &name);
		// Set size of window
		void setWindowSize(std::size_t width, std::size_t height);

		sf::Vector2i getWindowPosition() const;
		sf::Vector2u getWindowSize() const;
		// Returns the OpenGL context of the window
		const sf::ContextSettings& getWindowContext() const;

		std::size_t getFps() const;
		float getDelta() const;

		sf::Window& getWindow();

		EntityManager& getEntityManager();
		SystemManager& getSystemManager();
		WindowManager& getWindowManager();
		TagManager& getTagManager();
		GroupManager& getGroupManager();
		ScreenManager& getScreenManager();
	};
};

#endif