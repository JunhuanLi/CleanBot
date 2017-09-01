#include "Vehicle.h"


void Vehicle::Update(){
	//new acceleration velocity position orientation...
	//cout<<"Im in vehicle update function"<<endl;
	m_pStateMachine->UpdateState();
}

