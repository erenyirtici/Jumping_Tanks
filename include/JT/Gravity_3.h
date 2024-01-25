#pragma once
#include<iostream>
#include"Gravity_1.h"

class Gravity3 : public Gravity1
{
public:
	// for boss gravity control
	static bool Falling_End_ContEnemy(float y_location )
	{
		if (y_location >= 350)
		{
			return true ; 
		}
		else
		{
			return false;
		}
	}
	
private:
	
	
};