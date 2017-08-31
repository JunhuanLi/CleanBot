#pragma once
#include"State.h"
#include <cassert>
#include<string>
#include<iostream>
using namespace std;

class Vehicle;

class StateMachine{	
private:
	Vehicle* m_pOwner;
	State* m_pCurrentState;
	State* m_pPreviousState;
public:

	StateMachine(Vehicle* owner):m_pOwner(owner),
								 m_pCurrentState(NULL),
								 m_pPreviousState(NULL)
	{}

	virtual ~StateMachine(){}

	State*  GetCurrentState(){return m_pCurrentState;}
	State*  GetPreviousState(){return m_pPreviousState;}
	void SetPreviousState(State*  newState){m_pPreviousState = newState;}
	void SetCurrentState(State*  newState){m_pCurrentState = newState;}

	void UpdateState() const{
	cout<<"Im in statemachine update function."<<endl;
	m_pCurrentState->Execute(m_pOwner);
	}
	
	void ChangeState(State* pNewState){
		cout<<"Im inside of ChangeState function."<<endl;

		cout<<"Changing to "<<endl;
		assert(pNewState && 
			 "<StateMachine::ChangeState>: trying to change to NULL state");

		
		m_pCurrentState->Exit(m_pOwner);
		m_pCurrentState = pNewState;
		m_pCurrentState->Enter(m_pOwner);
	}

	void RevertToPreviousState(){
		ChangeState(m_pPreviousState);
	}
};

