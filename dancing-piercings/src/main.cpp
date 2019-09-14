#include "ofMain.h"
#include "ofApp.h"

int main()
{
	ofAppGlutWindow window;
	window.setGlutDisplayString("rgba double depth alpha samples>=4");
	ofSetupOpenGL(500, 500, OF_WINDOW);

	// ofGLWindowSettings settings;
    // settings.setGLVersion(3, 0);
	// settings.setSize(600, 600);
    // ofCreateWindow(settings);

	ofRunApp(new ofApp());
}
