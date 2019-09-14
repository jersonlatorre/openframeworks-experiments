#include "SteeringBehaviours.h"

ofVec3f SteeringBehaviours::seek(ofAgent *agent, ofAgent *target)
{
	agent->aDesired = (target->aPosition - agent->aPosition).getNormalized() * agent->aMaxSpeed;
	agent->aSteer = (agent->aDesired - agent->aVelocity).getLimited(agent->aMaxSteer);
	return agent->aSteer;
}