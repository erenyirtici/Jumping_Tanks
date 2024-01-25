#include<iostream>
#include<SFML/Graphics.hpp>
#include"Tank_2.h"




using namespace sf;
using namespace std;
//similar with tank1
void Tank_2::Move_Right()
{
	tank.move(speed, 0);
}

void Tank_2::Move_Left()
{
	tank.move(-speed, 0);
}

void Tank_2::Jumping()
{
	if (!Is_Flying)
	{
		this->vertical_velocity = -this->jumping_power;
		Is_Flying = true;
	}
}
void Tank_2::Taking_Damage(int amo_damage)
{
	health -= amo_damage;
	if (health < 0) {
		health = 0;
	}
}

FloatRect Tank_2::Return_Bounds(Sprite tanko)const
{
	return tanko.getGlobalBounds();
}

void Tank_2::Draw(RenderWindow& window, Sprite tanko, int helto)
{
	if (helto > 0)
	{
		window.draw(tanko);
	}
}

void Tank_2::Draw_Bullet(RenderWindow& window)
{


	for (const auto& bullet : magazine)
	{
		bullet.draw(window);
	}
}

void Tank_2::Draw_Snow(RenderWindow& window)
{


	for (const auto& Snow_Ball1 : magazine_snow)
	{
		Snow_Ball1.draw(window);
	}

}

void Tank_2::Draw_Big_Bullet(RenderWindow& window)
{


	for (const auto& Big_Bullet1 : magazine_Big_Bullet)
	{
		Big_Bullet1.draw(window);
	}

}

void Tank_2::Draw_Big_Bullets_Babies(RenderWindow& window)
{


	for (const auto& bullet : baybies_magezine)
	{
		bullet.draw(window);
	}

}

void Tank_2::Firing()
{
	float startX = tank.getPosition().x + tank.getLocalBounds().width;
	float startY = tank.getPosition().y + tank.getLocalBounds().height / 5.5;
	magazine.emplace_back(startX, startY);
}


void Tank_2::Firing_Snowball()
{
	float startX = tank.getPosition().x + tank.getLocalBounds().width;
	float startY = tank.getPosition().y + tank.getLocalBounds().height / 5.5;
	magazine_snow.emplace_back(startX, startY);
}

void Tank_2::Firing_Big_Bullet()
{
	float startX = tank.getPosition().x + tank.getLocalBounds().width;
	float startY = tank.getPosition().y + tank.getLocalBounds().height / 5.5;
	magazine_Big_Bullet.emplace_back(startX, startY);
}

void Tank_2::Droping_Baby_Bullets(float bangX, float bangY, int Drop_Vel)
{

	baybies_magezine.emplace_back(bangX, bangY, Drop_Vel);
}


Vector2f  Tank_2::LocRETURN()
{
	Vector2f loc(tank.getPosition().x, tank.getPosition().y);
	return loc;
}


int Tank_2::get_Health()
{
	return health;
}

float Tank_2::get_jumping_power()
{
	return jumping_power;
}


float Tank_2::get_speed()
{
	return speed;
}


