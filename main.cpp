#include <iostream>
#include "Vehicle.h"
#include "Vector2D.h"

using namespace std;

int main(){
	Vehicle v;

	while(!v.GetBusy()) {
		cout<<"Select Motion:"<<endl;
		cout<<"1.Waiting \n"
			<<"2.Cover \n"
			<<"3.NavToCharger \n"
			<<"4.Dock \n"
			<<"5.ObstacleAvoidance \n"
			<<"6.FollowWall  \n"
			<<"7.TurnOff \n";

		int motion;
		cin>>motion;

		switch(motion){ //function selection
			case 1: cout<<"Still waiting your selections!"<<endl;
				break;
			case 2: v.GetFSM()->ChangeState(new Cover);v.SetBusy(true);
				break;
			case 3: v.GetFSM()->ChangeState(new NavToCharger);v.SetBusy(true);
				break;
			case 4: v.GetFSM()->ChangeState(new Dock);v.SetBusy(true);
				break;
			case 5: v.GetFSM()->ChangeState(new ObstacleAvoidance);v.SetBusy(true);
				break;
			case 6:v.GetFSM()->ChangeState(new FollowWall);v.SetBusy(true);
				break;
			case 7: v.GetFSM()->ChangeState(new TurnOff);v.SetBusy(true);
				break;
			default: cout<<"Please select a valid function!"<<endl;
				break;
		}
	}

	//设定采样时间
	//需要中断来切换状态

	for(int i=0; i<4; i++)
		v.Update();
	// finished or failed and waiting orders
	system("pause");
	return 0;
};