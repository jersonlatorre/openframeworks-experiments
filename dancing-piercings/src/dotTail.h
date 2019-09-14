#pragma once

#include "ofPoint.h"
#include "ofColor.h"

class dotTail
{
public:
	dotTail();
	void setNumPoints(int);
	void setPosition(ofPoint);
	void update();
	void draw();

	unsigned int numPoints;
	float t = 0;
	std::vector<glm::vec3> points;
};