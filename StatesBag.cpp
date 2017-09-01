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
	//监测下一指令
	
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
	

	//监测各种状态
	//监测是否成功完成
	//切换到下一状态 


}

void Cover::Exit(Vehicle* v){
	cout<<"Exiting Cover state."<<endl;
}

//================================================================================
//==============================    NavToCharger      ============================
//================================================================================
void NavToCharger::Enter(Vehicle* v){
	cout<<"Entering NavToCharger state."<<endl;
	
}

void NavToCharger::Execute(Vehicle* v){
	cout<<"Executing NavToCharger state."<<endl;
	Navigation* m_pNav = new Navigation(v);
	if(v->IsChargeLocationUpdated()){

		m_pNav->P2PMoving( v->GetChargerLocation() );
	
	}
	else {


		//寻找充电座坐标 FindChargerLocation()



		m_pNav->P2PMoving( v->GetChargerLocation() );
	}
	
	if(m_pNav->IsSucceed() == true){
		cout<<"Entering Dock state!"<<endl;
		v->GetFSM()->ChangeState(new Dock);
	} else {
		cout<<"未能到达充电地点！报警！"<<endl;



		//导航失败处理。。。


		v->GetFSM()->ChangeState(new Dock);
	}
	
}

void NavToCharger::Exit(Vehicle* v){
	cout<<"Exiting NavToCharger state."<<endl;
}

//================================================================================
//==============================    Dock      ====================================
//================================================================================
void Dock::Enter(Vehicle* v){
	cout<<"Entering Dock state."<<endl;
}

void Dock::Execute(Vehicle* v){
	cout<<"Executing Dock state."<<endl;

	//dock连环动作调用
	//各种状态监测

	//if(matched)
	//v->SetCharging(true)
	if(v->IsCharging()){
		cout<<"Im charging!"<<endl;
		//while(v->GetPower() < 1.0){
			//wait untill fully charged...
		//}
	}
	
	cout<<"Charging is finished!"<<endl;
	cout<<"Recovering the previous job!"<<endl;
	v->GetFSM()->RevertToPreviousState();
}

void Dock::Exit(Vehicle* v){
	cout<<"Exiting Dock state."<<endl;
}

//================================================================================
//==============================    FollowWall     ===============================
//================================================================================
void FollowWall::Enter(Vehicle* v){
	cout<<"Entering FollowWall state."<<endl;
}

void FollowWall::Execute(Vehicle* v){
	cout<<"Executing FollowWall state."<<endl;



	//建立地图



	//发现充电座就记录
	//v->SetChargerLocation();


	//监测各种状态



	//如果完成就切换到覆盖状态

	//失败后处理
}

void FollowWall::Exit(Vehicle* v){
	cout<<"Exiting FollowWall state."<<endl;
}

//================================================================================
//==============================    ObstacleAvoidance     ========================
//================================================================================
void ObstacleAvoidance::Enter(Vehicle* v){
	cout<<"Entering ObstacleAvoidance state."<<endl;
}

void ObstacleAvoidance::Execute(Vehicle* v){
	cout<<"Executing ObstacleAvoidance state."<<endl;


	//避障算法
		//各种状态监测





	//避障成功返回上一状态
	//避障失败报警




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



	//转换到等待状态或者关机
	//数据要保留
	//确保再次开机能继续之前的工作




}

void TurnOff::Exit(Vehicle* v){
	cout<<"Exiting TurnOff state."<<endl;
}