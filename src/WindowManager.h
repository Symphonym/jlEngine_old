#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <unordered_map>
#include <string>
#include <SFML/Window.hpp>

namespace jl
{
	class WindowManager
	{
	private:

		std::unordered_map<std::string, sf::Window*> m_windows;

	public:

		WindowManager() = default;
		~WindowManager();

		sf::Window& createWindow(const std::string &name);
		void removeWindow(const std::string &name);

		// Activates specified Window, making it active for OpenGL rendering
		void activate(const std::string &name);

		sf::Window* getWindow(const std::string &name);
		const sf::Window* getWindow(const std::string &name) const;
	};
};

#endif