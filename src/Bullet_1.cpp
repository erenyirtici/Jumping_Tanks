#include<iostream>
#include"Bullet_1.h"
#include<SFML/Graphics.hpp>
#include"Gravity_1.h"

using namespace sf;
using namespace std;

//for the movement of the our bulletes
void Bullet::Bullet_Move_Per()
{
    bullet.move(fire_speed, 0);
}
//for dropping baby bullets
void Bullet::Bullet_Drop_Per()
{
    bullet.move(0, inittial_fall += Gravity1::Get_Gravity());
}
//for enemy
void Bullet::Bullet_Move_Per_eNEMY()
{
    bullet.move(-fire_speed, 0);
}
//for drawing
void Bullet::draw(RenderWindow& window)const
{
    window.draw(bullet);
}
//for checking out of bound
bool Bullet::Is_Out_Of_Bound()const
{

    if ((bullet.getPosition().x) - (initial_x) > 800)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//checking for enemy
bool Bullet::Is_Out_Of_Bound_Enemy()const
{

    if ((initial_x)-(bullet.getPosition().x) > 800)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//for detecting collison
bool Bullet::Collision_Detector(const FloatRect& Enemy_Bounds) const
{
    if (bullet.getGlobalBounds().intersects(Enemy_Bounds) == true)
    {

        return true;
    }
}
//for clearing bullets
void Bullet::Bullet_Bin()
{
    bullet.setPosition(10000, 10000);
}
