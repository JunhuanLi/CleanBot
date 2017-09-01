#pragma once
#include "Navigation.h"
#include "Vehicle.h"

void Navigation::P2PMoving(Vector2D target){
		CalculatePath(target);
		while( this->m_pOwner->GetVehiclePosition() != target){
			//keep moving

			/*
			if(delta_t > 30 in a small area){
				SetSucceed(false);
				cout<<"Navigation failed!"<<endl;
				break;
			}
			*/
		}
		SetSucceed(true); 
		cout<<"Navigation finished!"<<endl;

	}