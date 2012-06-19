//
//  EventSystem.h
//  Complex
//
//  Created by Till Hagger on 6/4/12.
//  Copyright (c) 2012 Till Hagger. All rights reserved.
//

#ifndef COMPLEX_I_EVENT_H_
#define COMPLEX_I_EVENT_H_

namespace complex
{
	typedef std::string EventType;

	class IEvent
	{
		EventType getType();
	};
}

#endif