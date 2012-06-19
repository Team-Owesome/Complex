#include <iostream>

#include "core/EventSystem.h"
#include "core/EntitySystem.h"

int main()
{
	complex::EntitySystem entitySystem;
	
	complex::EntityID id = entitySystem.createEntity();
	complex::EntityID id2 = entitySystem.createEntity();
	complex::EntityID id3 = entitySystem.createEntity();
	
	entitySystem.addComponent(id, new complex::Component());
	entitySystem.addComponent(id, new complex::Component());
	entitySystem.addComponent(id, new complex::Component());
	entitySystem.addComponent(id, new complex::Component());

	const complex::ComponentList &list = entitySystem.getComponentList(id, complex::ComponentType("Component"));

    while (1)
    {
		std::cout << id << ',' << id2 << ',' << id3 << list.at(0)->getType() << '\n';


		entitySystem.destroyEntity(id3);
		entitySystem.destroyEntity(id);

		id = entitySystem.createEntity();
		id3 = entitySystem.createEntity();
    }
}