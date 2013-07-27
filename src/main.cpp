#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Engine.h"
#include "Entity.h"

int main(int argc, const char *args[])
{

	jl::Engine engine;
	jl::WindowManager& wm = engine.getWindowManager();
	sf::Window& window = wm.createWindow("StartWindow");
	window.create(sf::VideoMode(800, 600), "HelloWorld", sf::Style::None);
	window.setPosition(sf::Vector2i(200, 100));

	jl::EntityManager& em = engine.getEntityManager();
	jl::Entity& en1 = em.createEntity();

	sf::Clock clock;
	while(window.isOpen())
	{
		if(clock.getElapsedTime().asSeconds() > 5)
			window.close();

		window.display();
	}

	return 0;
}