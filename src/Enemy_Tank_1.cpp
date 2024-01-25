#include<iostream>
#include<SFML/Graphics.hpp>
#include"Enemy_Tank_1.h"

using namespace sf;
using namespace std;
//for moving right
void Enemy_Tank::Move_Right()
{
	tank.move(speed, 0);
}
//for moving left
void  Enemy_Tank::Move_Left()
{
	tank.move(-speed, 0);
}





//for jumping
void  Enemy_Tank::Jumping()
{
	if (!Is_Flying)
	{
		this->vertical_velocity = -this->jumping_power;
		Is_Flying = true;
	}
}
//for taking damage
void  Enemy_Tank::Taking_Damage(int amo_damage)
{
	health -= amo_damage;
	if (health < 0) {
		health = 0;
	}
}
//for firing
void  Enemy_Tank::Firing()
{
	float startX = tank.getPosition().x;
	float startY = tank.getPosition().y + tank.getLocalBounds().height / 5.5;
	magazine.emplace_back(startX, startY);
}

//for drawing bullet
void  Enemy_Tank::Draw_Bullet(RenderWindow& window)
{
	for (const auto& bullet : magazine) {
		bullet.draw(window);
	}
}


//for returning location
Vector2f Enemy_Tank::LocRETURN()
{
	Vector2f loc(tank.getPosition().x, tank.getPosition().y);
	return loc;
}

//for returning bounds
FloatRect Enemy_Tank::Return_Bounds()const
{
	return tank.getGlobalBounds();
}

