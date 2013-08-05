#include "Entity.h"
#include "Component.h"
#include "Engine.h"

namespace jl
{
	Entity::Entity(Engine *engine, IdType id) : 
		m_engine(engine),
		m_id(id),
		m_enabled(true)
	{

	}

	Entity::~Entity()
	{
		removeAllComponents();
	}

	void Entity::addComponent(Component *component)
	{
		std::size_t hashCode = typeid(*component).hash_code();

		// Overwrite existing component, unless it's the one we're trying to add
		if(component != getComponent(hashCode))
			removeComponent(hashCode);

		// Move assignment operator is invoked, so no need for us to move
		m_components[hashCode] = ComponentPtr(component);
		refresh();
	}
	void Entity::removeComponent(std::size_t hashCode)
	{
		auto itr = m_components.find(hashCode);
		if(itr != m_components.end())
		{
			m_components.erase(itr);
			refresh();
		}
	}
	void Entity::removeComponent(Component *component)
	{
		removeComponent(typeid(*component).hash_code());
	}
	void Entity::recycle()
	{
		m_engine->getEntityManager().recycleEntity(*this);
	}
	void Entity::refresh()
	{
		m_engine->getSystemManager().refreshEntity(*this);
	}
	void Entity::removeAllComponents()
	{
		m_components.clear();
		refresh();
	}

	void Entity::setTag(const std::string &tag)
	{
		m_engine->getTagManager().tagEntity(*this, tag);
	}
	void Entity::setGroup(const std::string &group)
	{
		m_engine->getGroupManager().addToGroup(*this, group);
	}
	void Entity::setStatus(bool status)
	{
		m_engine->getEntityManager().setEntityStatus(*this, status);
	}

	void Entity::removeTag()
	{
		m_engine->getTagManager().untagEntity(*this);
	}
	void Entity::removeFromGroup(const std::string &group)
	{
		m_engine->getGroupManager().removeFromGroup(*this, group);
	}
	void Entity::removeFromGroups()
	{
		m_engine->getGroupManager().removeFromGroups(*this);
	}

	Component* Entity::getComponent(std::size_t hashCode)
	{
		auto itr = m_components.find(hashCode);
		return itr != m_components.end() ? itr->second.get() : nullptr;
	}

	const Entity::ComponentBag& Entity::getAllComponents() const
	{
		return m_components;
	}
	bool Entity::isEnabled() const
	{
		return m_enabled;
	}
	std::size_t Entity::getComponentCount() const
	{
		return m_components.size();
	}
	IdType Entity::getId() const
	{
		return m_id;
	}
};