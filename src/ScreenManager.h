#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <vector>

namespace jl
{
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

		std::vector<Screen*> m_stack;


	};
};

#endif 