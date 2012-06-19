//
//  EventSystem.h
//  Complex
//
//  Created by Till Hagger on 6/4/12.
//  Copyright (c) 2012 Till Hagger. All rights reserved.
//

#ifndef COMPLEX_EVENT_SYSTEM_H_
#define COMPLEX_EVENT_SYSTEM_H_

#include <string>

#include "IEventListener.h"
#include "IEvent.h"

namespace complex
{

    class EventSystem
    {
        void addListener(IEventListener* listener, EventType type);
		void removeListener(IEventListener* listener, EventType type);

		void fireEvent(IEvent* event);
    };
}

#endif
