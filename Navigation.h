#pragma once
#include<queue>
#include"Vector2D.h"

class Navigation
{
private:
	std::queue<Vector2D> m_pPath;
public:
	Navigation(){}

	~Navigation(void);
	
	std::queue<Vector2D> Calculate(Vector2D targetpoint){
		//get a path from current point to target point
		//Calculate the path using algorithms 
		//m_pPath.push()
		return m_pPath;
	}
};

