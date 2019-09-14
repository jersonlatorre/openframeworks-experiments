#include "Follower.h"
#include "Target.h"
#include "ia/steeringbehaviours/SteeringBehaviours.h"

Follower::Follower()
{
	aMaxSpeed = 30;
	aMaxSteer = 0.2;

	setWidth(5);
	setHeight(5);
	setDepth(5);

	aVelocity = ofVec3f(0, 0, aMaxSpeed);
}

void Follower::setTarget(Target target)
{
	this->target = target;
}

void Follower::update()
{
	aUpdate(getPosition());
	target.aUpdate(target.getPosition());

	aVelocity += SteeringBehaviours::seek((ofAgent*)this, (ofAgent*)&target);
	aPosition += aVelocity * ofGetLastFrameTime();
	
	setPosition(aPosition);
}