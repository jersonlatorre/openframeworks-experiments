#pragma once

#include "ofVec3f.h"

class ofAgent
{
	public:
		float aMaxSpeed;
		float aMaxSteer;
		ofVec3f aPosition;
		ofVec3f aVelocity;
		ofVec3f aDesired;
		ofVec3f aSteer;

		void aUpdate(ofVec3f);
		void aUpdate(ofVec3f, ofVec3f);
};