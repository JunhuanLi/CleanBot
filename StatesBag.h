#ifndef STATES_BAG_H
#define STATES_BAG_H

#include "State.h"

class Waiting : public State{
public:
	Waiting(){}
	~Waiting(){}

	virtual void Enter(Vehicle* v);

	virtual void Execute(Vehicle* v);

	virtual void Exit(Vehicle* v);
};

class Cover : public State{
public:
	Cover(){}
	~Cover(){}

	virtual void Enter(Vehicle* v);

	virtual void Execute(Vehicle* v);

	virtual void Exit(Vehicle* v);
};

class NavToCharger : public State{
public:
	Dock(){}
	~Dock(){}

	virtual void Enter(Vehicle* v);

	virtual void Execute(Vehicle* v);

	virtual void Exit(Vehicle* v);
};

class FollowWall : public State{
public:
	FollowWall(){}
	~FollowWall(){}
	virtual void Enter(Vehicle* v);

	virtual void Execute(Vehicle* v);

	virtual void Exit(Vehicle* v);
};

class ObstacleAvoidance : public State{
public:
	ObstacleAvoidance(){}
	~ObstacleAvoidance(){}

	virtual void Enter(Vehicle* v);

	virtual void Execute(Vehicle* v);

	virtual void Exit(Vehicle* v);
};

class TurnOff : public State{
public:
	TurnOff(){}
	~TurnOff(){}

	virtual void Enter(Vehicle* v);

	virtual void Execute(Vehicle* v);

	virtual void Exit(Vehicle* v);
};
#endif