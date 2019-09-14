#include "Pen.h"
#include "of3dGraphics.h"
#include "ofGraphics.h"

Pen::Pen()
{
	lastPosition = position = ofVec3f(0, 0, 0);

	phaseX = ofRandom(0, 100);
	phaseY = ofRandom(0, 100);
	phaseZ = ofRandom(0, 100);
	wX = ofRandom(0.07, 0.12);
	wY = ofRandom(0.07, 0.12);
	wZ = ofRandom(0.07, 0.12);
}

void Pen::update()
{
	lastPosition = position;

	position.x = 250 * (ofNoise(ofGetElapsedTimef() * wX + phaseX) - 0.5);
	position.y = 250 * (ofNoise(ofGetElapsedTimef() * wY + phaseY) - 0.5);
	position.z = 250 * (ofNoise(ofGetElapsedTimef() * wZ + phaseZ) - 0.5);

	velocity = position - lastPosition;
}

void Pen::draw()
{
	// ofSetColor(240, 0, 60);
	// ofDrawSphere(position, .0);
}