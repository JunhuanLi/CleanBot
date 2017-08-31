#pragma once
class SteeringBehaviors
{
public:
	SteeringBehaviors(void);
	~SteeringBehaviors(void);
	void foward(double force);
	void backward(double force);
	void rotate(double angle);

};

