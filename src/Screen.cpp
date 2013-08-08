#include "Screen.h"
#include "Engine.h"

namespace jl
{
	Screen::Screen()
	{

	}

	void Screen::setScreen(const std::string &name, Screen *screen)
	{
		m_engine->getScreenManager().setScreen(name, screen);
	}
	void Screen::pushScreen(const std::string &name, Screen *screen)
	{
		m_engine->getScreenManager().pushScreen(name, screen);
	}
	void Screen::popScreen()
	{
		m_engine->getScreenManager().popScreen();
	}

	void Screen::setEventTransparency(bool transparency)
	{
		m_transparencyBits.set(0, transparency);
	}
	void Screen::setUpdateTransparency(bool transparency)
	{
		m_transparencyBits.set(1, transparency);
	}
	void Screen::setDrawTransparency(bool transparency)
	{
		m_transparencyBits.set(2, transparency);
	}

	bool Screen::isEventTransparent() const
	{
		return m_transparencyBits.test(0);
	}
	bool Screen::isUpdateTransparent() const
	{
		return m_transparencyBits.test(1);
	}
	bool Screen::isDrawTransparent() const
	{
		return m_transparencyBits.test(2);
	}

	Engine& Screen::getEngine()
	{
		return *m_engine;
	}

	std::string Screen::getName() const
	{
		return m_name;
	}
};