#include "StateMachine.h"
#include "StatesBag.h"
#include <iostream>
using namespace std;

class Vehicle{
private:
	StateMachine* m_pStateMachine;
	bool Busy;
	bool Charging;
	double Power;
public:

	enum Motion {Wait=1,Cover, Dock, FollowWall, ObstacleAvoidance, Stop};

	Vehicle(){
		m_pStateMachine = new StateMachine(this);
		m_pStateMachine->SetCurrentState(new Waiting);
		Charging  = false;
		Busy = false;
		Power = 1;
	}

	~Vehicle();
	void Update();
	bool IsCharging(){return Charging;}
	bool GetBusy(){return Busy;}
	void SetBusy(bool b){Busy = b;}
	double GetPower();
	StateMachine* GetFSM(){return m_pStateMachine;}

};
