#include "Screen.h"
#include "Engine.h"

namespace jl
{

	Screen::Screen(Engine *engine, const std::string &name) :
		m_name(name),
		m_engine(engine),
		m_manager(&engine->getScreenManager())
	{

	}

	void Screen::setScreen(Screen *screen)
	{
		m_manager->setScreen(screen);
	}
	void Screen::pushScreen(Screen *screen)
	{
		m_manager->pushScreen(screen);
	}
	void Screen::popScreen()
	{
		m_manager->popScreen();
	}

	void Screen::setEventTransparency(bool transparency)
	{
		m_transparencyBits.set(TransparencyBits::Event, transparency);
	}
	void Screen::setUpdateTransparency(bool transparency)
	{
		m_transparencyBits.set(TransparencyBits::Update, transparency);
	}
	void Screen::setDrawTransparency(bool transparency)
	{
		m_transparencyBits.set(TransparencyBits::Draw, transparency);
	}

	bool Screen::isEventTransparent() const
	{
		return m_transparencyBits.test(TransparencyBits::Event);
	}
	bool Screen::isUpdateTransparent() const
	{
		return m_transparencyBits.test(TransparencyBits::Update);
	}
	bool Screen::isDrawTransparent() const
	{
		return m_transparencyBits.test(TransparencyBits::Draw);
	}

	std::string Screen::getName() const
	{
		return m_name;
	}
};