#ifndef ENTITY_H
#define ENTITY_H

#include <unordered_map>
#include <string>
#include <typeinfo>

namespace jl
{
	class Engine;
	class Component;
	class Entity
	{
	private:

		typedef std::unordered_map<std::size_t, jl::Component*> ComponentBag;

		ComponentBag m_components;
		Engine *m_engine;
		int m_id;
		bool m_enabled;

		friend class EntityManager;

		// Disable copying
		Entity(const Entity &entity) = delete;
		Entity& operator= (const Entity &entity) = delete;

		// Make constructor private so that only the EntityManager
		// can create an Entity.
		explicit Entity(Engine *engine, int id);
	public:

		// Ensure that the Entity's Components are deallocated in dtor
		// as we cannot make sure that th
		virtual ~Entity();

		void addComponent(Component *component);

		// Immidiately delete said component
		void removeComponent(Component *component);
		template<typename T> void removeComponent()
		{
			removeComponent(typeid(T).hash_code());
		};
		void removeComponent(std::size_t hashCode); // Used almost exclusively internally

		// Removes all components and sets the Entity's state to disabled, as
		// all functionality has been removed from it.
		void removeAllComponents();

		// Marks entity for recycling
		void recycle();
		// Refreshes Entity amongst the Systems
		void refresh();

		// Set a custom string tag for an Entity by which it can be identified.
		void setTag(const std::string &tag);
		// Add the Entity to a group by the specified name. The Entity can be
		// located in multiple groups at the same time.
		void setGroup(const std::string &group);
		// Whether or not the Entity should be processed by Systems
		void setStatus(bool status);

		// Untags the entity
		void removeTag();
		// Remove Entity from a single group or all groups it's
		// associated with respectively.
		void removeFromGroup(const std::string &group);
		void removeFromGroups();


		// Returns a pointer to the component of type T. If such a component
		// does not exist within the Entity, nullptr is returned.
		template<typename T> T* getComponent()
		{
			Component *component = getComponent(typeid(T).hash_code());
			return component != nullptr ? static_cast<T*>(component) : nullptr;
		};
		Component* getComponent(std::size_t hashCode); // Used almost exclusively internally


		// Returns a read-only version of the component bag
		const ComponentBag& getAllComponents() const;

		bool isEnabled() const;
		std::size_t getComponentCount() const;
		int getId() const;
	};
};

#endif 