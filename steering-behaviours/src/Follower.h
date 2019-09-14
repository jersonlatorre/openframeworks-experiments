#pragma once

#include "Follower.h"
#include "Target.h"
#include "ia/steeringbehaviours/ofAgent.h"

class Follower : public ofBoxPrimitive, public ofAgent
{
	private:
		Target target;

	public:
		Follower();
		void setTarget(Target);
		void update();
	};