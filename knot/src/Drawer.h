#pragma once

#include "ofVec3f.h"
#include "Drawer.h"
#include "Pen.h"

class Drawer
{
private:
	int HISTORY_LENGTH = 50;
	ofVec3f *history;
	int hue;

public:
	Drawer();
	Pen pen;
	void draw();
	void update();
	ofVec3f getPenPosition();
};