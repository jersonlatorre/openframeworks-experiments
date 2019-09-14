#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetCircleResolution(50);
	ofEnableDepthTest();
	ofSetVerticalSync(true);
	ofEnableAntiAliasing();
	ofEnableSmoothing();
	ofSetFrameRate(30);
	ofDisableArbTex();

	ofFbo::Settings settings;
	settings.useDepth = false;
	settings.width = ofGetWidth();
	settings.height = ofGetHeight();
	settings.numSamples = 4;
	bufferBackground.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 4);
	bufferTails.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 4);
	buffer.allocate(settings);

	seed = 220;

	shader.load("", "shader.frag");
}

//--------------------------------------------------------------
void ofApp::update()
{
	float x = 0.3 * ofGetHeight() * ofNoise(t * 1.0 + seed, 0);
	float y = 0.3 * ofGetHeight() * ofNoise(0, t * 0.8 + seed);
	tail.setPosition(ofPoint(x, y));
	t += ofGetLastFrameTime() * 0.9;
	// t += 0.025;

	generateBackground();
	generateTails();
	composeAll();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);
	// shader.begin();
	// shader.setUniformTexture("u_background", buffer.getTexture(), 0);
	// shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	// shader.setUniform1f("u_time", t);
	// ofSetColor(255);
	// ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	// shader.end();

	// buffer.getTexture().bind();
	// ofFill();
	// ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	// ofRotateXDeg(t * 30);
	// ofRotateYDeg(t * 25);
	// ofRotateZDeg(t * 20);
	// ofDrawBox(300);
	// buffer.getTexture().unbind();

	buffer.draw(0, 0);

	// ofSaveScreen("images/" + ofToString(ofGetFrameNum()) + ".png");
}

void ofApp::generateBackground()
{
	bufferBackground.begin();

	ofClear(255);
	ofBackground(0, 0, 0, 200);

	// glEnable(GL_DEPTH_TEST);

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotateDeg(-t * 20);

	for (int i = 0; i < N; i++)
	{
		ofRotateDeg(360.0 / (float)N);
		ofSetColor(ofColor::fromHsb(255 * (0.5 + 0.5 * cos(t / 4)), 240, 240));
		ofDrawTriangle(0, 0, ofGetWidth(), 0, ofGetWidth(), ofGetWidth() / 4);
	}

	ofDrawCircle(0, 0, 30 + 10 * cos(t * 2));

	bufferBackground.end();
}

void ofApp::generateTails()
{
	bufferTails.begin();
	ofClear(255, 255, 255, 0);
	tail.draw();
	bufferTails.end();
}

void ofApp::composeAll()
{
	buffer.begin();

	ofClear(255, 255, 255, 0);
	bufferBackground.draw(0, 0);
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotateDeg(t * 15);

	for (int i = 0; i < N; i++)
	{
		ofRotateDeg(360 / (float)N);
		bufferTails.draw(0, 0);
	}

	buffer.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	
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