#include<iostream>
#include<SFML/Graphics.hpp>
#include"Enemy_Tank_3.h"

using namespace sf;
using namespace std;


//for moving right
void Enemy_Tank_3::Move_Right()
{
	Enemy_Tank1.move(speed, 0);
}
//for moving left
void Enemy_Tank_3::Move_Left()
{
	Enemy_Tank1.move(-speed, 0);
}
//for jumping
void Enemy_Tank_3::Jumping()
{
	if (!Is_Flying)
	{
		vertical_velocity = -jumping_power;
		Is_Flying = true;
	}
}
//for taking damage
void Enemy_Tank_3::Taking_Damage(int amo_damage)
{
	health -= amo_damage;
	if (health < 0) {
		health = 0;
	}
}
//for drawing bullets
void Enemy_Tank_3::Draw_Bullet(RenderWindow& window)
{


	for (const auto& bullet : magazine)
	{
		bullet.draw(window);
	}
}
//for drawing big bullets
void Enemy_Tank_3::Draw_Big_Bullet(RenderWindow& window)
{


	for (const auto& Big_Bullet1 : magazine_Big_Bullet_enemy)
	{
		Big_Bullet1.draw(window);
	}

}
// for drawing babies 
void Enemy_Tank_3::Draw_Big_Bullets_Babies(RenderWindow& window)
{


	for (const auto& bullet : babiesmagazinenemy)
	{
		bullet.draw(window);
	}

}
// for firing
void Enemy_Tank_3::Firing() {
	float startX = Enemy_Tank1.getPosition().x;
	float startY = Enemy_Tank1.getPosition().y + Enemy_Tank1.getLocalBounds().height / 1.4;
	magazine.emplace_back(startX, startY);
}
//firing for bigbullet
void Enemy_Tank_3::Firing_Big_Bullet() {
	float startX = Enemy_Tank1.getPosition().x;
	float startY = Enemy_Tank1.getPosition().y + Enemy_Tank1.getLocalBounds().height / 3.8;
	magazine_Big_Bullet_enemy.emplace_back(startX, startY);
}
//for droppingbaby bullets
void Enemy_Tank_3::Droping_Baby_Bullets(float bangX, float bangY, int Drop_Vel) {
	babiesmagazinenemy.emplace_back(bangX, bangY, Drop_Vel);
}
// for returning locations
Vector2f  Enemy_Tank_3::LocRETURN()
{
	Vector2f loc(Enemy_Tank1.getPosition().x, Enemy_Tank1.getPosition().y);
	return loc;

}


