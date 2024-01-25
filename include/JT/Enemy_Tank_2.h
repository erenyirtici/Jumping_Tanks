#pragma once
#include"Bullet_2.h"
#include"Gravity_2.h"
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Tank_2.h"

using namespace sf;
using namespace std;


class Enemy_Tank_2 : public Tank_2
{
public:
	Enemy_Tank_2()
	{
		Enemy_Tank_Texture.loadFromFile("level2tank.png");
		Enemy_Tank1.setTexture(Enemy_Tank_Texture);
		Enemy_Tank1.setPosition(700, 550);

		
		vertical_velocity = 0.0f;
		speed = 0.2f;
		jumping_power = 0.50f;

		health = 100;

		isJump = false;
	}

	void Move_Right();
	void Move_Left();

	void Jumping();
	void Taking_Damage(int amo_damage)override;

	void Firing()override;
	void Draw_Bullet(RenderWindow& window)override;

	Vector2f LocRETURN();

	void Draw_Snow(RenderWindow& window)override;

	void Firing_Snowball()override;




public:
	

	
	Sprite Enemy_Tank1;

	Texture Enemy_Tank_Texture;

	Bullet_2 bullet;
	Snow_Ball_2 Snow_Ball1;

	vector<Bullet_2> magazine;
	vector<Snow_Ball_2> magazine_snow;

	RectangleShape health_Bar;

	bool Is_Flying;
	bool isJump;

};