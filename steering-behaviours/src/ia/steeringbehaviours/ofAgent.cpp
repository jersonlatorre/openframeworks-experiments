#include "ofAgent.h"

void ofAgent::aUpdate(ofVec3f position)
{
	aPosition = position;
}

void ofAgent::aUpdate(ofVec3f position, ofVec3f velocity)
{
	aPosition = position;
	aVelocity = velocity;
}