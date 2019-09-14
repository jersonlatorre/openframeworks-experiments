#pragma once

#include "Follower.h"
#include "Target.h"
#include "ofMain.h"

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

		const int N = 1000;
		const int RADIUS = 100;
		float timer = 0;
		ofSpherePrimitive** dots;
		ofEasyCam cam;
		Follower follower;
		Target target;
		bool isPaused = false;
};