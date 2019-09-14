#pragma once

#include "ofVec3f.h"
#include "ofAgent.h"

class SteeringBehaviours
{
	public:
		static ofVec3f seek(ofAgent*, ofAgent*);
};