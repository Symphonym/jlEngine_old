#ifndef JL_SCREENMANAGER_H
#define JL_SCREENMANAGER_H

#include <vector>
#include <memory>
#include <deque>

#include <SFML/Window/Event.hpp>

namespace jl
{
	class Engine;
	class Screen;
	class ScreenManager
	{
	private:


		/* HOW IT SHOULD BE IMPLEMENTED
		http://gamedev.stackexchange.com/questions/2423/alternative-to-game-state-system
	I think you're just arguing semantics here. It's called Game State because it behaves 
	like a Finite State Machine, with a finite number of states and transitions between 
	them. The 'Game' in 'Game State System' refers to the overall system, with 'Loading', 
	'MainMenu' etc being states of the game. These could easily be called 'scenes' or '
	screens' or 'levels'. Its just semantics.
	I'm not sure that a strict FSM applies anymore. In my implementations I call states 
	'Screens' and allow them to be stackable - ie. screens can be drawn on top of other 
	screens, controlling whether or not screens below them are updated or drawn. In this 
	way, I can have multiple screens active at the same time with self-contained logic and 
	code specific to that screen, without having to worry about any other screen.
	A Pause screen, for example, could be opened on top of my main gameplay screen that 
	disallows updates, but allows drawing below itself. A character inventory screen could 
	allow both drawing and updates - so the game keeps playing while you're working in your 
	inventory.
		*/
		typedef std::unique_ptr<Screen> ScreenPtr;
		typedef std::vector<ScreenPtr> ScreenStack;

		ScreenStack m_stack;
		std::deque<ScreenPtr> m_deleteQueue;

		// Purely for informatic purposes, seeing what Screens manager is going through
		typedef std::vector<const Screen*> ReadOnly_ScreenStack;
		// TODO I dunno about these mutables
		mutable ReadOnly_ScreenStack m_eventScreens, m_updateScreens, m_drawScreens;

		Engine *m_engine;

	public:
		ScreenManager(Engine *engine);
		~ScreenManager();

		// Issues all delete requests in the delete queue, effectively clearing it.
		void issueDeleteRequests();

		// Removes all Screens from stack and pushes the specified Screen onto it.
		void setScreen(const std::string &name, Screen *screen);
		// Pushes the specified Screen onto the top of the stack
		void pushScreen(const std::string &name, Screen *screen);
		// Pops the Screen at the top of the stack, making the Screen below active.
		void popScreen();

		// If the stack is empty or not
		bool isEmpty() const;

		ScreenStack& getStack();

		// Returns a read-only list of the Screens that will have its
		// event/update/draw method processed when the game ticks. The topmost
		// element will always correspond to the screen at the top of the stack.
		const ReadOnly_ScreenStack& getEventScreens() const;
		const ReadOnly_ScreenStack& getUpdateScreens() const;
		const ReadOnly_ScreenStack& getDrawScreens() const;



		std::size_t getStackSize() const;


	};
};

#endif 