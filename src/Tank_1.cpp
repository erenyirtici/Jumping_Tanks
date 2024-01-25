#include<iostream>
#include<SFML/Graphics.hpp>
#include"Tank_1.h"

using namespace sf;
using namespace std;
//for moving right
void Tank ::Move_Right()
{
	tank.move(speed, 0);
}
//for moving left
void Tank::Move_Left()
{
	tank.move(-speed, 0);
}
//for jumping
void Tank::Jumping()
{
	if (!Is_Flying)
	{
		this->vertical_velocity = -this->jumping_power;
		Is_Flying = true;
	}
}
//for taking damage
void Tank::Taking_Damage(int amo_damage)
{
	health -= amo_damage;
	if (health < 0) {
		health = 0;
	}
}


//for returning tank or enemy tank bounds
FloatRect Tank::Do_Return_Bounds(Tank& tanki)const
{
	 return tanki.Return_Bounds();
}
//for returning bounds
FloatRect Tank :: Return_Bounds()const
{
	return tank.getGlobalBounds();
}
//for drawing tank
void Tank::Draw(RenderWindow& window, Sprite tanko, int helto)
{
	if (helto > 0)
	{
		window.draw(tanko);
	}
}
//for drawing bullets 
void Tank::Draw_Bullet(RenderWindow& window)
{


	for (const auto& bullet : magazine)
	{
		bullet.draw(window);
	}
}
//for drawing snow 
void Tank::Draw_Snow(RenderWindow& window)
{


	for (const auto& Snow_Ball1 : magazine_snow)
	{
		Snow_Ball1.draw(window);
	}

}
// for drawing big bullets
void Tank::Draw_Big_Bullet(RenderWindow& window)
{


	for (const auto& Big_Bullet1 : magazine_Big_Bullet)
	{
		Big_Bullet1.draw(window);
	}

}
//for drawing babies
void Tank::Draw_Big_Bullets_Babies(RenderWindow& window)
{


	for (const auto& bullet : baybies_magezine)
	{
		bullet.draw(window);
	}

}
//for firing
void Tank::Firing()
{
	float startX = tank.getPosition().x + tank.getLocalBounds().width;
	float startY = tank.getPosition().y + tank.getLocalBounds().height / 5.5;
	magazine.emplace_back(startX, startY);
}

//for firing snow
void Tank::Firing_Snowball()
{
	float startX = tank.getPosition().x + tank.getLocalBounds().width;
	float startY = tank.getPosition().y + tank.getLocalBounds().height / 5.5;
	magazine_snow.emplace_back(startX, startY);
}
//for firing big bullet
void Tank::Firing_Big_Bullet()
{
	float startX = tank.getPosition().x + tank.getLocalBounds().width;
	float startY = tank.getPosition().y + tank.getLocalBounds().height / 5.5;
	magazine_Big_Bullet.emplace_back(startX, startY);
}
//for dopping bullets
void Tank::Droping_Baby_Bullets(float bangX, float bangY, int Drop_Vel)
{

	baybies_magezine.emplace_back(bangX, bangY, Drop_Vel);
}
//for returnig health
int Tank::get_Health()
{
	return health;
}
//for returning jump power
float Tank::get_jumping_power()
{
	return jumping_power;
}

//for returning speed
float Tank::get_speed()
{
	return speed;
}





