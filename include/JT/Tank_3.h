#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Bullet_3.h"
#include"Gravity_3.h"
#include"Snow_Ball_3.h";
#include"Big_Bullet_3.h"




using namespace sf;
using namespace std;

class Tank_3
{
public:
	Tank_3()
	{
		Tank_Texture.loadFromFile("Tank.png");
		tank.setTexture(Tank_Texture);
		tank.setPosition(0, 550);

		

		vertical_velocity = 0.0f;
		speed = 0.2f;
		jumping_power = 0.25f;

		health = 100;

		isJump = false;

	}

	virtual ~Tank_3()
	{

	}


	void Move_Right();

	void Move_Left();

	void Jumping();

	virtual void Taking_Damage(int amo_damage);

	FloatRect Return_Bounds(Sprite tanko)const;


	virtual void Draw(RenderWindow& window, Sprite tanko, int helto);

	virtual void Draw_Bullet(RenderWindow& window);

	virtual void Draw_Snow(RenderWindow& window);

	virtual void Draw_Big_Bullet(RenderWindow& window);

	virtual void Draw_Big_Bullets_Babies(RenderWindow& window);

	virtual void Firing();

	virtual void Firing_Snowball();

	virtual void Firing_Big_Bullet();

	virtual void Droping_Baby_Bullets(float bangX, float bangY, int Drop_Vel);

	Vector2f  LocRETURN();

	int get_Health();

	float get_speed();

	float get_jumping_power();

	

protected:
	int health;
	float speed;
	float jumping_power;
	
public:
	float vertical_velocity;

	Sprite tank;

	Texture Tank_Texture;

	Bullet_3 bullet;
	Snow_Ball_3 Snow_Ball1;
	Big_Bullet_3 Big_Bullet1 ;


	vector<Bullet_3> magazine;
	vector<Snow_Ball_3> magazine_snow;
	vector<Big_Bullet_3> magazine_Big_Bullet;

	
	vector<Bullet_3> baybies_magezine ;

	RectangleShape health_Bar;



	bool Is_Flying;
	bool isJump;

};
