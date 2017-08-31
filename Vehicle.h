#ifndef VEHICLE_H
#define VEHICLE_H

#include "StateMachine.h"
#include "StatesBag.h"
#include "Navigation.h"
//#include "State.h"
#include <iostream>
using namespace std;

class Vehicle{
private:
	StateMachine* m_pStateMachine;
	Navigation* m_pNav;
	Vector2D m_ChargerLocation;
	Vector2D VehiclePosition;

	bool Busy;
	bool ChargeLocationUpdated;
	bool Charging;
	double Power;
public:

	//enum Motion {Wait=1,Cover, Dock, FollowWall, ObstacleAvoidance, Stop};

	Vehicle(){
		m_pStateMachine = new StateMachine(this);
		m_pStateMachine->SetCurrentState(new Waiting);
		m_pNav = new Navigation(this);
		m_ChargerLocation = Vector2D();
		VehiclePosition = Vector2D();

		Busy = false;
		ChargeLocationUpdated = false;
		Charging  = false;
		Power = 1;
	}

	~Vehicle(){
		delete m_pStateMachine;
		//delete m_pNav;
	}
	void Update();

	bool IsCharging(){return Charging;}

	bool GetBusy(){return Busy;}
	void SetBusy(bool b){Busy = b;}

	double GetPower(){
		Power = 0.1; //actually read from sensor
		return Power;
	}

	StateMachine* GetFSM(){return m_pStateMachine;}

	Navigation* GetNav(){return m_pNav;}

	Vector2D GetVehiclePosition(){return VehiclePosition;}

	Vector2D GetChargerLocation(){return m_ChargerLocation;}
	bool IsChargeLocationUpdated(){return ChargeLocationUpdated;}
	void SetChargerLocation(Vector2D loc){m_ChargerLocation = loc; ChargeLocationUpdated = true;}

};

#endif