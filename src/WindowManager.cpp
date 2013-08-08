#include "WindowManager.h"

namespace jl
{
	WindowManager::WindowManager() :
		m_activeEventWindow("")
	{

	}

	WindowManager::~WindowManager()
	{
		m_windows.clear();
	}

	sf::Window& WindowManager::createWindow(const std::string &name)
	{
		m_windows[name] = WindowPtr(new sf::Window());
		return *m_windows[name];
	}
	void WindowManager::removeWindow(const std::string &name)
	{
		auto itr = m_windows.find(name);
		if(itr != m_windows.end())
			m_windows.erase(itr);
	}

	void WindowManager::activate(const std::string &name)
	{
		auto itr = m_windows.find(name);
		if(itr != m_windows.end());
		{
			itr->second->setActive(true);
			m_activeEventWindow = name;
		}
	}
	void WindowManager::activateEvents(const std::string &name)
	{
		auto itr = m_windows.find(name);
		if(itr != m_windows.end());
			m_activeEventWindow = name;
	}
	void WindowManager::activateOpenGL(const std::string &name)
	{
		auto itr = m_windows.find(name);
		if(itr != m_windows.end());
			itr->second->setActive(true);
	}

	bool WindowManager::isEventWindow(const std::string &name) const
	{
		return name == m_activeEventWindow;
	}

	sf::Window& WindowManager::getWindow(const std::string &name)
	{
		return *m_windows.at(name);
	}
	const sf::Window& WindowManager::getWindow(const std::string &name) const
	{
		return *m_windows.at(name);
	}

	sf::Window& WindowManager::getEventWindow()
	{
		*m_windows.at(m_activeEventWindow);
	}
};