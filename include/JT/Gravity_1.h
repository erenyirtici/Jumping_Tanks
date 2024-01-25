#pragma once
#include<iostream>


class Gravity1
{
public:
	// for giving gravity constant
	static float Get_Gravity()
	{
		return 0.0005f;
	}
	// for controlling end of falling event
	static bool  Falling_End_Cont(float y_location)
	{
		if (y_location >= 550)
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