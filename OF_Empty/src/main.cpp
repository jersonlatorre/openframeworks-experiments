#include "ofMain.h"
#include "ofApp.h"

int main()
{
	// ofAppGlutWindow window;
	// window.setGlutDisplayString("rgba double depth alpha samples>=4");
	// ofSetupOpenGL(&window, 600, 600, OF_WINDOW);
	// ofRunApp(new ofApp());

	// can be OF_WINDOW or OF_FULLSCREEN
    ofSetupOpenGL(600, 600, OF_WINDOW); // <-------- setup the GL context
	ofRunApp(new ofApp());
}
