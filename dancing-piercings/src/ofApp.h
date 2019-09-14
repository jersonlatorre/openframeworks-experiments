#pragma once

#include "ofMain.h"
#include "dotTail.h"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void generateTails();
	void generateBackground();
	void composeAll();

	ofShader shader;
	ofFbo bufferBackground;
	ofFbo bufferTails;
	ofFbo buffer;
	dotTail tail;
	float t = 0;
	int N = 7;
	int seed;
};