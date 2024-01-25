#pragma once
#include"Bullet_3.h"
#include"Gravity_3.h"
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Tank_3.h"

using namespace sf;
using namespace std;


class Enemy_Tank_3 : public Tank_3
{
public:
	Enemy_Tank_3()
	{
		Enemy_Tank_Texture.loadFromFile("Tankenemy3.png");
		Enemy_Tank1.setTexture(Enemy_Tank_Texture);
		Enemy_Tank1.setPosition(700, 550);

		

		vertical_velocity = 0.0f;
		speed = 0.2f;
		jumping_power = 0.35f;

		health = 2000;

		isJump = false;
	}

	void Move_Right();

	void Move_Left();


	void Jumping();


	void Taking_Damage(int amo_damage) override;


	void Draw_Bullet(RenderWindow& window)override;

	void Draw_Big_Bullet(RenderWindow& window)override;

	void Draw_Big_Bullets_Babies(RenderWindow& window)override;

	void Firing()override;

	void Firing_Big_Bullet()override;

	void Droping_Baby_Bullets(float bangX, float bangY, int Drop_Vel)override;

	Vector2f  LocRETURN();

	
public:
	

	
	Sprite Enemy_Tank1;

	Texture Enemy_Tank_Texture;

	Bullet_3 bullet;
	Big_Bullet_3 Big_Bullet2;

	vector<Bullet_3> magazine;

	vector<Big_Bullet_3> magazine_Big_Bullet_enemy;

	vector<Bullet_3> babiesmagazinenemy;

	RectangleShape health_Bar;

	bool Is_Flying;
	bool isJump;

};