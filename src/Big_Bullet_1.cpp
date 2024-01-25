#include<iostream>
#include"Big_Bullet_1.h"
#include<SFML/Graphics.hpp>


using namespace sf;
using namespace std;

//for the movement of the our bulletes
void Big_Bullet::Big_Bullet_Move_Per()
{
    Big_Bullet1.move(fire_speed, 0);
}
//for enemy
void Big_Bullet::Big_Bullet_Move_Per_eNEMY()
{
    Big_Bullet1.move(-fire_speed, 0);
}
//for drawing
void Big_Bullet::draw(RenderWindow& window)const
{
    window.draw(Big_Bullet1);
}
//checking the bounds
bool  Big_Bullet::Is_Out_Of_Bound()const
{

    if ((Big_Bullet1.getPosition().x) - (initial_x) > 500)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//checking for enemy
bool Big_Bullet::Is_Out_Of_Bound_Enemy()const
{

    if ((initial_x)-(Big_Bullet1.getPosition().x) > 600)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//for collision detection
bool Big_Bullet::Collision_Detector(const FloatRect& Enemy_Bounds) const
{
    if (Big_Bullet1.getGlobalBounds().intersects(Enemy_Bounds) == true)
    {

        return true;
    }
}
//for clearing the bullets
void Big_Bullet::Bullet_Bin()
{
    Big_Bullet1.setPosition(10000, 10000);
}
//for returning bullets bounds
FloatRect   Big_Bullet::Return_Bounds()const
{
    return Big_Bullet1.getGlobalBounds();
}

//for returning bullets cordinates
Vector2f Big_Bullet::Retun_Bang_Cordinates()
{
    Vector2f bang_point(Big_Bullet1.getPosition().x, Big_Bullet1.getPosition().y);

    return bang_point;
}