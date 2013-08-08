#ifndef JL_SCREEN_H
#define JL_SCREEN_H

#include <SFML/Window/Event.hpp>
#include <bitset>
#include <string>

namespace jl
{
	class Engine;
	class Screen
	{
	private:

		friend class ScreenManager;
		/* TODO
		enum class TransparencyBits
		{
			Event = 0,
			Update = 1,
			Draw = 2
		};*/

		// || Draw Transparency || Update Transparency || Event Transparency ||
		Engine *m_engine;
		std::string m_name;
		std::bitset<3> m_transparencyBits;

	protected:

		Screen();

		void setScreen(const std::string &name, Screen *screen);
		void pushScreen(const std::string &name, Screen *screen);
		void popScreen();

		void setEventTransparency(bool transparency);
		void setUpdateTransparency(bool transparency);
		void setDrawTransparency(bool transparency);

		Engine& getEngine();

	public:

		// This method gets called once when the Screen given to the
		// ScreenManager. A valid pointer to the Engine class is also
		// guaranteed within this method.
		virtual void setup(Engine *engine){};

		virtual void events(sf::Event &event) = 0;
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