#include "Drawer.h"
#include "ofGraphics.h"
#include "ofEvents.h"
#include "ofMath.h"

Drawer::Drawer()
{
	this->hue = ofRandom(255);

	history = new ofVec3f[HISTORY_LENGTH];

	for (int i = 0; i < HISTORY_LENGTH; i++)
	{
		history[i] = ofVec3f(0, 0, 0);
	}

	for (int i = 0; i < HISTORY_LENGTH; i++)
	{
		this->update();
	}
}

void Drawer::update()
{
	pen.update();

	for (int i = 0; i < HISTORY_LENGTH - 1; i++)
	{
		history[i] = history[i + 1];
	}

	history[HISTORY_LENGTH - 1] = pen.position;
}

void Drawer::draw()
{
	ofSetLineWidth(10);

	for (int i = 0; i < HISTORY_LENGTH - 1; i++)
	{
		// ofSetColor(ofColor::fromHsb(hue, 255, 255));
		ofSetColor(ofColor::fromHsb(255 * i / HISTORY_LENGTH, 255, 255, 255 * i / HISTORY_LENGTH));
		ofDrawLine(history[i], history[i + 1]);
	}

	pen.draw();
}