#include "dotTail.h"
#include "ofGraphics.h"
#include "ofPolyline.h"
#include "ofMath.h"
#include "ofUtils.h"

dotTail::dotTail()
{
	setNumPoints(10);
}

void dotTail::setNumPoints(int numPoints)
{
	this->numPoints = numPoints;
}

void dotTail::setPosition(ofPoint position)
{
	points.push_back(position);

	while (points.size() > numPoints)
	{
		points.erase(points.begin());
	}
}

void dotTail::update()
{
	if (points.size() > 0)
		points.erase(points.begin());
}

void dotTail::draw()
{
	ofPolyline *line = new ofPolyline();
	line->addVertices(points);

	ofSetLineWidth(50);
	ofSetColor(255);
	ofFill();
	line->draw();
	delete line;
}