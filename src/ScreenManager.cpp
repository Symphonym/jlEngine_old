#include "ScreenManager.h"
#include "Screen.h"

namespace jl
{
	ScreenManager::ScreenManager(Engine *engine) :
		m_deleteRequests(0),
		m_engine(engine)
	{

	}
	ScreenManager::~ScreenManager()
	{
		m_stack.clear();
	}

	void ScreenManager::issueDeleteRequests()
	{
		if(!m_stack.empty())
		{
			for(int i = 0; i < m_deleteRequests; i++)
				m_stack.pop_back();
		}

		// New stack is now on top
		if(!m_stack.empty())
			m_stack.back()->onEnter();

		m_deleteRequests = 0;
	}

	void ScreenManager::setScreen(Screen *screen)
	{
		while(!m_stack.empty())
			popScreen();

		pushScreen(screen);
	}
	void ScreenManager::pushScreen(Screen *screen)
	{
		if(!m_stack.empty())
			m_stack.back()->onLeave();

		screen->onEnter();
		m_stack.push_back(ScreenPtr(screen));
	}
	void ScreenManager::popScreen()
	{
		++m_deleteRequests;
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
		for(int i = 0; i < m_stack.size(); i++)
		{
			std::size_t indexAbove = i + 1;
			if((indexAbove < m_stack.size() && m_stack[indexAbove]->isEventTransparent()) ||
				indexAbove >= m_stack.size()) // Top-most Screen, will naturally get called
				m_eventScreens.push_back(m_stack[i].get());
		}

		return m_eventScreens;
	}
	const ScreenManager::ReadOnly_ScreenStack& ScreenManager::getUpdateScreens() const
	{
		m_updateScreens.clear();
		for(int i = 0; i < m_stack.size(); i++)
		{
			std::size_t indexAbove = i + 1;
			if((indexAbove < m_stack.size() && m_stack[indexAbove]->isUpdateTransparent()) ||
				indexAbove >= m_stack.size()) // Top-most Screen, will naturally get called
				m_updateScreens.push_back(m_stack[i].get());
		}

		return m_updateScreens;
	}
	const ScreenManager::ReadOnly_ScreenStack& ScreenManager::getDrawScreens() const
	{
		m_drawScreens.clear();
		for(int i = 0; i < m_stack.size(); i++)
		{
			std::size_t indexAbove = i + 1;
			if((indexAbove < m_stack.size() && m_stack[indexAbove]->isDrawTransparent()) ||
				indexAbove >= m_stack.size()) // Top-most Screen, will naturally get called
				m_drawScreens.push_back(m_stack[i].get());
		}

		return m_drawScreens;
	}

	std::size_t ScreenManager::getStackSize() const
	{
		return m_stack.size();
	}
};