#include "System.h"
#include "Component.h"
#include "Engine.h"
#include "Entity.h"
#include <bitset>

namespace jl
{
	System::System() : 
		m_enabled(true),
		m_engine(nullptr)
	{
		
	}


	void System::addTargetComponent(Component *component)
	{
		m_targetComponents.insert(typeid(*component).hash_code());
	}
	void System::removeTargetComponent(std::size_t hashCode)
	{
		auto itr = m_targetComponents.find(hashCode);
		if(itr != m_targetComponents.end())
			m_targetComponents.erase(itr);
	}
	void System::removeTargetComponent(Component *component)
	{
		removeTargetComponent(typeid(*component).hash_code());
	}	
	bool System::hasTargetComponent(Component *component) const
	{
		return m_targetComponents.find(typeid(*component).hash_code()) != m_targetComponents.end();
	}

	void System::refreshEntity(Entity &entity)
	{
		/* My fancy bit solution wasen't necessary it seems :/

		std::vector<bool> allBitsTrue(m_targetComponents.size());
		allBitsTrue.flip();

		std::vector<bool> targetBits;
		for(auto itr = m_targetComponents.begin(); itr != m_targetComponents.end(); itr++)
		{
			// Make sure the Entity has ALL the required Components
			if(entity.getComponent(*itr) != nullptr)
				targetBits.push_back(true);
			else
				break;
		}
		
		if(targetBits == allBitsTrue)
			m_activeEntities[entity.getId()] = &entity;
		else
		{
			auto eraseItr = m_activeEntities.find(entity.getId());
			if(eraseItr != m_activeEntities.end())
				m_activeEntities.erase(eraseItr); 
		}

		*/
		
		bool hasTheComponents = true;
		for(auto itr = m_targetComponents.begin(); itr != m_targetComponents.end(); itr++)
		{
			// Make sure the Entity has ALL the required Components
			if(entity.getComponent(*itr) == nullptr)
			{
				hasTheComponents = false;
				break;
			}
		}
		
		if(hasTheComponents)
			m_activeEntities[entity.getId()] = &entity;
		else
		{
			auto eraseItr = m_activeEntities.find(entity.getId());
			if(eraseItr != m_activeEntities.end())
				m_activeEntities.erase(eraseItr); 
		}
	}

	void System::setStatus(bool status)
	{
		m_engine->getSystemManager().setSystemStatus(this, status);
	}

	void System::process()
	{
		if(isEnabled())
		{
			preProcess();
			for(auto itr = m_activeEntities.begin(); itr != m_activeEntities.end(); itr++)
			{
				if(itr->second->isEnabled())
					processEntity(*itr->second);
			}
			postProcess();
		}
	}

	bool System::isEnabled() const
	{
		return m_enabled;
	}

	std::size_t System::getActiveEntityCount() const
	{
		return m_activeEntities.size();
	}
};