#include "ofApp.h"

inline float urand() { return rand() / (float) RAND_MAX; }

//--------------------------------------------------------------
void ofApp::setup()
{
	ofEnableDepthTest();
	ofBackground(0);
	// ofSetFrameRate(60);

	dots = new ofSpherePrimitive*[N];

	for (int i = 0; i < N; i++)
	{
		ofSeedRandom(ofGetSystemTimeMicros());

		// float x1 = ofRandomf();
		// float x2 = ofRandomf();

		// while (x1 * x1 + x2 * x2 >= 1)
		// {
		// 	x2 = ofRandomf();
		// }

		// float x = RADIUS * 2 * x1 * sqrt(1 - x1 * x1 - x2 * x2);
		// float y = RADIUS * 2 * x2 * sqrt(1 - x1 * x1 - x2 * x2);
		// float z = RADIUS * (1 - 2 * (x1 * x1 + x2 * x2));
		
		float x = RADIUS * 2 * (urand() - 0.5);
		float y = RADIUS * 2 * (urand() - 0.5);
		float z = RADIUS * 2 * (urand() - 0.5);

		ofVec3f p = ofVec3f(x, y, z);

		dots[i] = new ofSpherePrimitive();
		dots[i]->setRadius(0.2);
		dots[i]->setPosition(p);
	}

	target.setRadius(3);
	target.setPosition(dots[rand() % N]->getPosition());
	follower.setTarget(target);

	// cam.setPosition(ofVec3f(0, 0, 0));
	cam.setDistance(200);
	// cam.setFov(35);
	// cout << cam.getDistance() << endl;
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (isPaused) return;

	timer += ofGetLastFrameTime();

	if (timer >= 2)
	{
		timer = 0;
		target.setPosition(ofVec3f(ofRandomf() * 80, ofRandomf() * 80, ofRandomf() * 80));
		follower.setTarget(target);
	}

	follower.update();
	follower.lookAt(follower.getPosition() + follower.aVelocity);

	// cam.setPosition(follower.getPosition());
	// cam.lookAt(cam.getPosition() + ofGetLastFrameTime() * follower.aVelocity);

	// cam.setPosition(follower.getPosition() - follower.aVelocity.getNormalized() * 100);
	// cam.lookAt(follower);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	cam.begin();

	ofSetColor(255);
	for (int i = 0; i < N; i++)
	{
		dots[i]->draw();
	}

	ofSetColor(255, 0, 0);
	target.draw();

	ofSetColor(255, 255, 0);
	follower.draw();

	ofSetLineWidth(3);

	ofSetColor(255, 0, 0);
	ofDrawLine(follower.getPosition(), follower.getPosition() + follower.aDesired);

	ofSetColor(0, 0, 255);
	ofDrawLine(follower.getPosition(), follower.getPosition() + follower.aVelocity);

	ofSetColor(0, 255, 0);
	ofDrawLine(follower.getPosition() + follower.aVelocity, follower.getPosition() + follower.aVelocity + follower.aSteer * 10);

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 32)
	{
		isPaused = !isPaused;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
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