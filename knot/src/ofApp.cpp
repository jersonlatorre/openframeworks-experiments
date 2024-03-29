#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetVerticalSync(false);
  ofSetFrameRate(60);
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
}

//--------------------------------------------------------------
void ofApp::draw()
{
  cam.begin();
  t += .2;
  ofPushMatrix();
  ofRotateXDeg(t);
  ofRotateYDeg(t);
  ofRotateZDeg(t);

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