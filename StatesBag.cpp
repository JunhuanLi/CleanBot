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
	//�����һָ��
	
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
	

	//������״̬
	//����Ƿ�ɹ����
	//�л�����һ״̬ 


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


		//Ѱ�ҳ�������� FindChargerLocation()



		m_pNav->P2PMoving( v->GetChargerLocation() );
	}
	
	if(m_pNav->IsSucceed() == true){
		cout<<"Entering Dock state!"<<endl;
		v->GetFSM()->ChangeState(new Dock);
	} else {
		cout<<"δ�ܵ�����ص㣡������"<<endl;



		//����ʧ�ܴ�������


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

	//dock������������
	//����״̬���

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



	//������ͼ



	//���ֳ�����ͼ�¼
	//v->SetChargerLocation();


	//������״̬



	//�����ɾ��л�������״̬

	//ʧ�ܺ���
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


	//�����㷨
		//����״̬���





	//���ϳɹ�������һ״̬
	//����ʧ�ܱ���




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



	//ת�����ȴ�״̬���߹ػ�
	//����Ҫ����
	//ȷ���ٴο����ܼ���֮ǰ�Ĺ���




}

void TurnOff::Exit(Vehicle* v){
	cout<<"Exiting TurnOff state."<<endl;
}