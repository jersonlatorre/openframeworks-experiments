#include "Pen.h"
#include "of3dGraphics.h"
#include "ofGraphics.h"

Pen::Pen()
{
	lastPosition = position = ofVec3f(0, 0, 0);

	phaseX = ofRandom(0, 100);
	phaseY = ofRandom(0, 100);
	phaseZ = ofRandom(0, 100);
	wX = ofRandom(0.1, 0.3);
	wY = ofRandom(0.1, 0.3);
	wZ = ofRandom(0.1, 0.3);
	c = ofColor(0);
	c.setHsb(ofRandom(255), 255, 255);
}

void Pen::update()
{
	lastPosition = position;

	position.x = 400 * (ofNoise(ofGetElapsedTimef() * wX + phaseX) - 0.5);
	position.y = 400 * (ofNoise(ofGetElapsedTimef() * wY + phaseY) - 0.5);
	position.z = 400 * (ofNoise(ofGetElapsedTimef() * wZ + phaseZ) - 0.5);

	velocity = position - lastPosition;
}

void Pen::draw()
{
	ofSetColor(c);
	ofDrawSphere(position.x, position.y, position.z, 1);
}