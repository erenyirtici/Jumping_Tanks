#pragma once
#include"level_1.h"
#include"level_2.h"
#include"level_3.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"


using namespace std;
using namespace sf;



class Game_Engine
{

	
public:
	// To play all levels in order
	void Game(void)
	{
		
		
		
		
			if (episode1.Win_or_Lose==0)
			{
				episode1.play();

			}
			if (episode2.Win_or_Lose2 == 0 && episode1.Win_or_Lose == 1) {
				episode2.play();
			}
			if (episode3.Win_or_Lose3 == 0 && episode2.Win_or_Lose2 == 1 && episode1.Win_or_Lose == 1) {
				episode3.play();
			}
	}


private:
	level_1 episode1;
	level_2 episode2;
	level_3 episode3;
};