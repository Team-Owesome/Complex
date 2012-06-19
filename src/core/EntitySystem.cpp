//
//  EntitySystem.cpp
//  Complex
//
//  Created by Till Hagger on 6/4/12.
//  Copyright (c) 2012 DU DA. All rights reserved.
//

#include "EntitySystem.h"

using namespace complex;

ComponentList EntitySystem::EmptyList;

EntitySystem::EntitySystem()
{
	_nextId = 1;
}

EntityID EntitySystem::createEntity()
{
	if (!_removedIndicies.empty())
	{
		std::set<EntityID>::iterator iterator = _removedIndicies.begin();

		EntityID entityId = *iterator;
		_removedIndicies.erase(iterator);

		return entityId;
	}
	else
	{
		return _nextId++;
	}
}

void EntitySystem::destroyEntity(EntityID entityId)
{
	_removedIndicies.insert(entityId);
	_entities.erase(entityId);
}

void EntitySystem::addComponent(EntityID entityId, Component* component)
{
	std::vector<ComponentList>& entities = _components[component->getType()];
	
	if (entityId > entities.size())
	{
		entities.resize(entityId + 1);
	}

	ComponentList& componentList = entities[entityId];
	componentList.push_back(component);
}

void EntitySystem::removeComponent(EntityID entityId, Component* component)
{
	std::vector<ComponentList>& entities = _components[component->getType()];

	if(entityId >= entities.size())
	{
		return;
	}

	ComponentList& list = entities[entityId];
	for( ComponentList::iterator it = list.begin(); it != list.end(); ++it )
	{
		if(*it == component)
		{
			list.erase(it);
		}
	}
}

const ComponentList& EntitySystem::getComponentList(EntityID entityId, ComponentType componentType)
{
	const std::vector<ComponentList>& entities = _components[componentType];

	if(entityId >= entities.size())
	{
		return EmptyList;
	}

	return entities[entityId];
}