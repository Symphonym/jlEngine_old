#ifndef JL_WINDOWMANAGER_H
#define JL_WINDOWMANAGER_H

#include <unordered_map>
#include <string>
#include <memory>
#include <SFML/Window.hpp>

namespace jl
{
	class WindowManager
	{
	private:

		typedef std::unique_ptr<sf::Window> WindowPtr;

		std::unordered_map<std::string, WindowPtr> m_windows;
		std::string m_activeEventWindow; // Window active for polling events
		// We can't track which Window is active for OpenGL rendering as
		// this can be changed outside of the WindowManager.

	public:

		WindowManager();
		~WindowManager();

		sf::Window& createWindow(const std::string &name);
		void removeWindow(const std::string &name);

		// Activates specified Window for both event polling and OpenGL.
		// It is just a shortcut for calling "activateEvents" and "activateOpenGL"
		void activate(const std::string &name);

		// Make the specified window the active window for polling events
		void activateEvents(const std::string &name);
		// Make specified window the active window for OpenGL rendering
		void activateOpenGL(const std::string &name);

		// If the specified Windows is active for polling events
		bool isEventWindow(const std::string &name) const;

		sf::Window& getWindow(const std::string &name);
		const sf::Window& getWindow(const std::string &name) const;
		sf::Window& getEventWindow();
	};
};

#endif