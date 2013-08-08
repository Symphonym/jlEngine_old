#include "ScreenManager.h"
#include "Screen.h"

namespace jl
{
	ScreenManager::ScreenManager(Engine *engine) :
		m_engine(engine)
	{

	}
	ScreenManager::~ScreenManager()
	{
		m_stack.clear();
		m_deleteQueue.clear();
	}

	void ScreenManager::issueDeleteRequests()
	{
		m_deleteQueue.clear();
	}

	void ScreenManager::setScreen(const std::string &name, Screen *screen)
	{
		while(!m_stack.empty())
			popScreen();

		pushScreen(name, screen);
	}
	void ScreenManager::pushScreen(const std::string &name, Screen *screen)
	{
		screen->m_engine = m_engine;
		screen->m_name = name;
		screen->setup(m_engine);
		m_stack.push_back(ScreenPtr(screen));
	}
	void ScreenManager::popScreen()
	{
		m_deleteQueue.push_front(std::move(m_stack.back()));
		m_stack.pop_back();
	}

	bool ScreenManager::isEmpty() const
	{
		return m_stack.empty();
	}

	ScreenManager::ScreenStack& ScreenManager::getStack()
	{
		return m_stack;
	}
	const ScreenManager::ReadOnly_ScreenStack& ScreenManager::getEventScreens() const
	{
		m_eventScreens.clear();
		for(auto& screen : m_stack)
		{
			if(screen->isEventTransparent())
				m_eventScreens.push_back(screen.get());
		}

		return m_eventScreens;
	}
	const ScreenManager::ReadOnly_ScreenStack& ScreenManager::getUpdateScreens() const
	{
		m_updateScreens.clear();
		for(auto& screen : m_stack)
		{
			if(screen->isUpdateTransparent())
				m_updateScreens.push_back(screen.get());
		}

		return m_updateScreens;
	}
	const ScreenManager::ReadOnly_ScreenStack& ScreenManager::getDrawScreens() const
	{
		m_drawScreens.clear();
		for(auto& screen : m_stack)
		{
			if(screen->isDrawTransparent())
				m_drawScreens.push_back(screen.get());
		}

		return m_drawScreens;
	}

	std::size_t ScreenManager::getStackSize() const
	{
		return m_stack.size();
	}
};