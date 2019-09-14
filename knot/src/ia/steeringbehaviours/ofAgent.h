#pragma once

#include "ofVec3f.h"

class ofAgent
{
	public:
		float maxSpeed;
		float maxSteer;
		ofVec3f position;
		ofVec3f velocity;
		ofVec3f desired;
		ofVec3f steer;

		void update();
		void draw();
};