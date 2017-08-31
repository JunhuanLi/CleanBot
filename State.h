#ifndef STATE_H
#define STATE_H

class Vehicle;

class State{
public:
	virtual ~State(){}
	//this will execute when the state is entered
	virtual void Enter(Vehicle*)=0;

	//this is the states normal update function
	virtual void Execute(Vehicle*)=0;

	//this will execute when the state is exited. (My word, isn't
	//life full of surprises... ;o))
	virtual void Exit(Vehicle*)=0;
};

#endif