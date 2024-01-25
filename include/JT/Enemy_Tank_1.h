#pragma once
#include"Bullet_1.h"
#include"Gravity_1.h"
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Tank_1.h"

using namespace sf;
using namespace std;


class Enemy_Tank : public Tank
{
public:
	Enemy_Tank()
	{
		Enemy_Tank_Texture.loadFromFile("Tankenemy2.png");
		tank.setTexture(Enemy_Tank_Texture);
		tank.setPosition(700, 550);

		

		vertical_velocity = 0.0f;
		speed = 0.2f;
		jumping_power = 0.25f;

		health = 100;

		isJump = false;
	}

	void Move_Right();
	void Move_Left();

	void Jumping();
	void Taking_Damage(int amo_damage)override;

	void Firing()override;
	void Draw_Bullet(RenderWindow& window)override;

	FloatRect Return_Bounds()const override ;

	Vector2f LocRETURN();

	

public:


	
	Sprite tank;

	Texture Enemy_Tank_Texture;

	Bullet bullet;
	vector<Bullet> magazine;

	RectangleShape health_Bar;

	bool Is_Flying;
	bool isJump;

};