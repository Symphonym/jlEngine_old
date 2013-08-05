#ifndef JL_SCREEN_H
#define JL_SCREEN_H

namespace jl
{
	class Engine;
	class Screen
	{
	private:

		// Whether or not the Screen below gets updated
		bool m_updateTransparent;
		// Whether or not the Screen below gets drawn
		bool m_drawTransparent;

	protected:
		Engine *m_engine;

		Screen(Engine *engine);

		// TODO pushState and the like

	public:

		virtual void update() = 0;
		virtual void draw() = 0;
	};
};

#endif