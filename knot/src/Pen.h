#include "ofNode.h"

class Pen : ofNode
{
public:
	Pen();
	ofVec3f position;
	ofVec3f velocity;
	void update();
	void draw();

private:
	ofVec3f lastPosition;
	float phaseX;
	float phaseY;
	float phaseZ;
	float wX;
	float wY;
	float wZ;
	ofColor c;
};