#include "WindowManager.h"

namespace jl
{
	WindowManager::~WindowManager()
	{
		for(auto itr = m_windows.begin(); itr != m_windows.end(); itr++)
		{
			delete itr->second;
			itr->second = nullptr;
		}
		m_windows.clear();
	}

	sf::Window& WindowManager::createWindow(const std::string &name)
	{
		m_windows[name] = new sf::Window();
		return *m_windows[name];
	}
	void WindowManager::removeWindow(const std::string &name)
	{
		auto itr = m_windows.find(name);
		if(itr != m_windows.end())
		{
			delete itr->second;
			itr->second = nullptr;
			m_windows.erase(itr);
		}
	}

	void WindowManager::activate(const std::string &name)
	{
		auto itr = m_windows.find(name);
		if(itr != m_windows.end());
			itr->second->setActive(true);
	}

	sf::Window* WindowManager::getWindow(const std::string &name)
	{
		auto itr = m_windows.find(name);
		return itr != m_windows.end() ? itr->second : nullptr;
	}
	const sf::Window* WindowManager::getWindow(const std::string &name) const
	{
		auto itr = m_windows.find(name);
		return itr != m_windows.end() ? itr->second : nullptr;
	}
};