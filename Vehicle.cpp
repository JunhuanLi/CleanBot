#include "Vehicle.h"


Vehicle::~Vehicle()
{
}

double Vehicle::GetPower(){
	Power = 0.1; //actually read from sensor
	return Power;
}
void Vehicle::Update(){
	//new acceleration velocity position orientation...
	cout<<"Im in vehicle update function"<<endl;
	m_pStateMachine->UpdateState();
}

