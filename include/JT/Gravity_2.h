#pragma once
#include<iostream>
#include"Gravity_1.h"

class Gravity2 : public Gravity1
{
public:
	
	// for controlling end of falling event on the pumpkin
	static bool Falling_End_Cont_On_Box(float y_location)
	{
		if (y_location >= 360)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	
	
};