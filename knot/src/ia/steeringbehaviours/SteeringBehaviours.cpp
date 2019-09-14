#include "SteeringBehaviours.h"
#include "ofMath.h"

ofVec3f SteeringBehaviours::seek(ofAgent *agent, ofAgent *target)
{
	agent->desired = (target->position - agent->position).getNormalized() * agent->maxSpeed;
	agent->steer = (agent->desired - agent->velocity).getLimited(agent->maxSteer);
	return agent->steer;
}

ofVec3f SteeringBehaviours::flee(ofAgent *agent, ofAgent *target)
{
	agent->desired = (agent->position - target->position).getNormalized() * agent->maxSpeed;
	agent->steer = (agent->desired - agent->velocity).getLimited(agent->maxSteer);
	return agent->steer;
}

ofVec3f SteeringBehaviours::wander(ofAgent *agent, ofVec3f center, float maxRadius, float turnChance)
{
	if ((agent->position - center).length() > maxRadius)
	{
		agent->steer = (center - agent->position).getLimited(agent->maxSteer);
	}
	else if (ofRandomuf() < turnChance)
	{
		ofVec3f randomUnitVector = getRandomInUnitSphere();
		agent->steer = randomUnitVector.getLimited(agent->maxSteer);
	}

	return agent->steer;
}

ofVec3f SteeringBehaviours::getRandomInUnitSphere()
{
	float x1 = ofRandomf();
	float x2 = ofRandomf();

	while (x1 * x1 + x2 * x2 >= 1) x2 = ofRandomf();

	float x = 2 * x1 * sqrt(1 - x1 * x1 - x2 * x2);
	float y = 2 * x2 * sqrt(1 - x1 * x1 - x2 * x2);
	float z = 1 - 2 * (x1 * x1 + x2 * x2);

	return ofVec3f(x, y, z);
}