#ifndef NAVIGATION_H
#define NAVIGATION_H

#include<queue>
#include"Vector2D.h"

class Vehicle;

class Navigation
{
private:
	Vehicle* m_pOwner;
	std::queue<Vector2D> m_pPath;
public:
	Navigation(Vehicle* owner){ 
		m_pOwner = owner;
		m_pPath.push(Vector2D());
	}

	~Navigation(void);
	
	void CalculatePath(Vector2D targetpoint){

		//pop out the initialization point (0.0,0.0)
		m_pPath.pop();

		//get a path from current point to target point
		//Calculate the path using algorithms 
		//m_pPath.push()

		//update m_pPath
		
	}

	void P2PMoving(Vector2D target);
};

#endif