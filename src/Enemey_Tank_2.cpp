#include<iostream>
#include<SFML/Graphics.hpp>
#include"Enemy_Tank_2.h"

using namespace sf;
using namespace std;
 

//for moving right
void Enemy_Tank_2::Move_Right()
{
	Enemy_Tank1.move(speed, 0);
}

//for moving left
void  Enemy_Tank_2::Move_Left()
{
	Enemy_Tank1.move(-speed, 0);
}





//for jumping
void  Enemy_Tank_2::Jumping()
{
	if (!Is_Flying)
	{
		this->vertical_velocity = -this->jumping_power;
		Is_Flying = true;
	}
}
//for taking damage
void  Enemy_Tank_2::Taking_Damage(int amo_damage)
{
	health -= amo_damage;
	if (health < 0) {
		health = 0;
	}
}
//for firing
void  Enemy_Tank_2::Firing()
{
	float startX = Enemy_Tank1.getPosition().x;
	float startY = Enemy_Tank1.getPosition().y + Enemy_Tank1.getLocalBounds().height / 5.5;
	magazine.emplace_back(startX, startY);
}

//for drawing bullets
void  Enemy_Tank_2::Draw_Bullet(RenderWindow& window)
{
	for (const auto& bullet : magazine) {
		bullet.draw(window);
	}
}

//for returning location
Vector2f Enemy_Tank_2::LocRETURN()
{
	Vector2f loc(Enemy_Tank1.getPosition().x, Enemy_Tank1.getPosition().y);
	return loc;
}


//for drawing snow
void Enemy_Tank_2::Draw_Snow(RenderWindow& window)
{


	for (const auto& Snow_Ball1 : magazine_snow)
	{
		Snow_Ball1.draw(window);
	}

}
//for firing snowball
void Enemy_Tank_2::Firing_Snowball()
{
	float startX = Enemy_Tank1.getPosition().x;
	float startY = Enemy_Tank1.getPosition().y + Enemy_Tank1.getLocalBounds().height / 5.5;
	magazine_snow.emplace_back(startX, startY);
}


