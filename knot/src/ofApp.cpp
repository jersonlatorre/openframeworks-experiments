#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofEnableDepthTest();
	ofEnableAntiAliasing();
	ofBackground(255);

	cam.setDistance(100);
	drawers = new Drawer[N];
}

//--------------------------------------------------------------
void ofApp::update()
{
	
	for (int i = 0; i < N; i++)
	{
		drawers[i].update();
	}
	
	// cam.setPosition(drawers[0].pen.position - drawers[0].pen.velocity.getNormalized() * 10);
	// cam.lookAt(drawers[0].pen.position);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	cam.begin();
	t += .1;
	ofPushMatrix();
	// ofRotateXDeg(t);
	// ofRotateYDeg(t / 2);
	// ofRotateZDeg(t);

	for (int i = 0; i < N; i++)
	{
		drawers[i].draw();
	}

	ofPopMatrix();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	// ofSaveScreen("pic-" + ofToString(roundf(ofRandom(10000))) + ".png");
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}