#include <iostream>
#include "Vehicle.h"
#include "Vector2D.h"

using namespace std;

int main(){
	Vehicle v;
	for(int i=0; i<4; i++)
		v.Update();
	
	// finished or failed and waiting orders
	system("pause");
	return 0;
};