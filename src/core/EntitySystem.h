//
//  EntitySystem.cpp
//  Complex
//
//  Created by Till Hagger on 6/4/12.
//  Copyright (c) 2012 Till Hagger. All rights reserved.
//

#ifndef COMPLEX_ENTITY_SYSTEM_H_
#define COMPLEX_ENTITY_SYSTEM_H_

#include <vector>
#include <map>
#include <set>

#include "Entity.h"
#include "Component.h"

namespace complex
{
	typedef std::vector<Component*> ComponentList;

    class EntitySystem
    {
	public:
		EntitySystem();

		/**
		 * Creates a new entity which is represented as a ID
		 * @returns EntityID The ID representation of the entity
		 */
		EntityID createEntity();
		void destroyEntity(EntityID entityId);

		void addComponent(EntityID entityId, Component* component);
		void removeComponent(EntityID entityId, Component* component);

		/*void destroyAllComponents(EntityID entityId);
		void destroyAllComponentsOfType(EntityID entityId, ComponentType componentType);*/

		const ComponentList &getComponentList(EntityID entityId, ComponentType componentType);

	private:
		static ComponentList EmptyList;

		EntityID _nextId;

		std::set<EntityID> _entities;
		std::set<EntityID> _removedIndicies;

		std::map<ComponentType, std::vector<ComponentList>> _components;
    };
}

#endif