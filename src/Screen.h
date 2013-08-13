#ifndef JL_SCREEN_H
#define JL_SCREEN_H

#include <SFML/Window/Event.hpp>
#include <bitset>
#include <string>

namespace jl
{
	class Engine;
	class ScreenManager;
	class Screen
	{
	private:

		//friend class ScreenManager;

		enum TransparencyBits
		{
			Event = 0,
			Update = 1,
			Draw = 2
		};

		std::string m_name;
		std::bitset<3> m_transparencyBits;

	protected:

		Engine *m_engine; // Engine
		ScreenManager *m_manager; // ScreenManager

		explicit Screen(Engine *engine, const std::string &name = "No Name");

		void setScreen(Screen *screen);
		void pushScreen(Screen *screen);
		void popScreen();

		void setEventTransparency(bool transparency);
		void setUpdateTransparency(bool transparency);
		void setDrawTransparency(bool transparency);

	public:

		// Called when the Screen enters the top of the stack 
		virtual void onEnter(){};
		// Called when the Screen leaves the top of the stack, not when
		// it is removed from the stack entirely.
		virtual void onLeave(){};

		virtual void events(const sf::Event &event) = 0;
		virtual void update(double delta) = 0;
		virtual void draw() = 0;

		bool isEventTransparent() const;
		bool isUpdateTransparent() const;
		bool isDrawTransparent() const;

		// Returns the name of the Screen
		std::string getName() const;
	};
};

#endif