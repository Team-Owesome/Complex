//
//  EventSystem.h
//  Complex
//
//  Created by Till Hagger on 6/4/12.
//  Copyright (c) 2012 Till Hagger. All rights reserved.
//

#ifndef COMPLEX_I_EVENT_LISTENER_H_
#define COMPLEX_I_EVENT_LISTENER_H_

#include "IEvent.h"

namespace complex
{
    class IEventListener
    {
		void handleEvent(IEvent* event);
    };
}

#endif