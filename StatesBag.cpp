#include "StatesBag.h"
#include "State.h"
#include "Vehicle.h"


//================================================================================
//==============================    Waiting     ====================================
//================================================================================
void Waiting::Enter(Vehicle* v){
	cout<<"Entering Waiting state."<<endl;
}

void Waiting::Execute(Vehicle* v){
	cout<<"Executing Waiting state."<<endl;

	while(!v->GetBusy()) {
		cout<<"Select Motion:"<<endl;
		cout<<"1.Waiting \n"
			<<"2.Cover \n"
			<<"3.Dock \n"
			<<"4.FollowWall \n"
			//<<"5.ObstacleAvoidance \n"
			<<"6.TurnOff \n";
		int motion;
		cin>>motion;
		switch(motion){ //function selection
			case 1: cout<<"Still waiting your selections!"<<endl;
				break;
			case 2: v->GetFSM()->ChangeState(new Cover);v->SetBusy(true);
				break;
			case 3: v->GetFSM()->ChangeState(new Dock);v->SetBusy(true);
				break;
			case 4: v->GetFSM()->ChangeState(new FollowWall);v->SetBusy(true);
				break;
			//case 5: v->GetFSM()->ChangeState(new ObstacleAvoidance);busy = true;
				break;
			case 6: v->GetFSM()->ChangeState(new TurnOff);v->SetBusy(true);
				break;
			default: cout<<"Please select a valid function!"<<endl;
				break;
		}
	}
}

void Waiting::Exit(Vehicle* v){
	cout<<"Exiting Waiting state."<<endl;
}
//================================================================================
//==============================    Cover     ====================================
//================================================================================
void Cover::Enter(Vehicle* v){
	
	cout<<"Entering Cover state."<<endl;

}

void Cover::Execute(Vehicle* v){
	cout<<"Executing Cover state."<<endl;
	if(v->GetPower() < 0.2){
		cout<<"The battery is low, going to charge myself!"<<endl;
		v->GetFSM()->ChangeState(new NavToCharger);
	}
}

void Cover::Exit(Vehicle* v){
	cout<<"Exiting Cover state."<<endl;
}

//================================================================================
//==============================    Dock      ====================================
//================================================================================
void NavToCharger::Enter(Vehicle* v){
	cout<<"Entering Dock state."<<endl;
}

void NavToCharger::Execute(Vehicle* v){
	cout<<"Executing Dock state."<<endl;

	//A* algorithm to the charger
	//....
	
	if(v->IsCharging()){
		cout<<"Im charging!"<<endl;
	}
	//while(v->GetPower() < 1.0){
		//charge
	//}
	cout<<"Charging is finished!"<<endl;
	cout<<"Recovering the previous job!"<<endl;
	v->GetFSM()->RevertToPreviousState();
}

void NavToCharger::Exit(Vehicle* v){
	cout<<"Exiting Dock state."<<endl;
}

//================================================================================
//==============================    FollowWall     ===============================
//================================================================================
void FollowWall::Enter(Vehicle* v){
	cout<<"Entering FollowWall state."<<endl;
}

void FollowWall::Execute(Vehicle* v){
	cout<<"Executing Waiting state."<<endl;
}

void FollowWall::Exit(Vehicle* v){
	cout<<"Exiting Waiting state."<<endl;
}

//================================================================================
//==============================    ObstacleAvoidance     ========================
//================================================================================
void ObstacleAvoidance::Enter(Vehicle* v){
	cout<<"Entering ObstacleAvoidance state."<<endl;
}

void ObstacleAvoidance::Execute(Vehicle* v){
	cout<<"Executing ObstacleAvoidance state."<<endl;
}

void ObstacleAvoidance::Exit(Vehicle* v){
	cout<<"Exiting ObstacleAvoidance state."<<endl;
}

//================================================================================
//==============================    TurnOff     ==================================
//================================================================================
void TurnOff::Enter(Vehicle* v){
	cout<<"Entering TurnOff state."<<endl;
}

void TurnOff::Execute(Vehicle* v){
	cout<<"Executing TurnOff state."<<endl;
}

void TurnOff::Exit(Vehicle* v){
	cout<<"Exiting TurnOff state."<<endl;
}