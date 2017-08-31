#pragma once
#include "Navigation.h"
#include "Vehicle.h"

void Navigation::P2PMoving(Vector2D target){
		CalculatePath(target);
		while( this->m_pOwner->GetVehiclePosition() != target){
			//keep moving
		}

	}