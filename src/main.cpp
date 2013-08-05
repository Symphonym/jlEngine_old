#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Engine.h"
#include "Entity.h"
#include "System.h"
#include "Component.h"

class CollidableComponent : public jl::Component
{

};
class PositionComponent : public jl::Component
{

};
class ColliderSystem : public jl::System
{
public:
	ColliderSystem()
	{
		addTargetComponent<PositionComponent>();
		addTargetComponent<CollidableComponent>();
	};
	virtual void processEntity(jl::Entity &entity)
	{

	};
};

int main(int argc, const char *args[])
{

	jl::Engine engine;
	jl::WindowManager& wm = engine.getWindowManager();
	//sf::Window& window = wm.createWindow("StartWindow");
	//window.create(sf::VideoMode(800, 600), "HelloWorld", sf::Style::None);
	//window.setPosition(sf::Vector2i(200, 100));

	jl::SystemManager& sm = engine.getSystemManager();
	//sm.addSystem(new ColliderSystem());

	//ColliderSystem* sys = sm.getSystem<ColliderSystem>();
	//std::cout << "Active entities: " << sys->getActiveEntityCount() << std::endl;

	jl::EntityManager& em = engine.getEntityManager();
	//jl::Entity& en1 = em.createEntity();
	/*en1.addComponent(new CollidableComponent());
	en1.addComponent(new PositionComponent());

	std::cout << "Active entities: " << sys->getActiveEntityCount() << std::endl;

	en1.removeComponent<CollidableComponent>();
	std::cout << "Active entities: " << sys->getActiveEntityCount() << std::endl;
*/
/*	jl::GroupManager& gm = engine.getGroupManager();
	std::cout << "en1 in group=" << gm.isInGroup(en1, "actors") << std::endl;
	en1.setGroup("actors");

	std::cout << "en1 in group=" << gm.isInGroup(en1, "actors") << std::endl;
	en1.removeFromGroup("actors");
	std::cout << "en1 in group=" << gm.isInGroup(en1, "actors") << std::endl;
*/
	/*sf::Clock clock;
	while(window.isOpen())
	{
		if(clock.getElapsedTime().asSeconds() > 1)
			window.close();

		window.display();
	}*/

	return 0;
}