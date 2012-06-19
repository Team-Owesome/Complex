#ifndef COMPLEX_COMPONENT_H_
#define COMPLEX_COMPONENT_H_

#include <string>

namespace complex
{
	typedef std::string ComponentType;

	class Component
	{
	public:
		ComponentType getType();
	};
}

#endif