#pragma once

#include "ofVec3f.h"
#include "ofAgent.h"

class SteeringBehaviours
{
	public:
		static ofVec3f seek(ofAgent*, ofAgent*);
		static ofVec3f flee(ofAgent*, ofAgent*);
		static ofVec3f wander(ofAgent*, ofVec3f, float, float);
	
	private:
		static ofVec3f getRandomInUnitSphere();
};