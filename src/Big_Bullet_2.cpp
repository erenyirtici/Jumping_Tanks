#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Big_Bullet_2.h"

using namespace sf;
using namespace std;

//for the movement of the our bulletes
void Big_Bullet_2::Big_Bullet_Move_Per()
{
    Big_Bullet1.move(fire_speed, 0);
}
//for enemy
void Big_Bullet_2::Big_Bullet_Move_Per_eNEMY()
{
    Big_Bullet1.move(-fire_speed, 0);
}
//for drawing
void Big_Bullet_2::draw(RenderWindow& window)const
{
    window.draw(Big_Bullet1);
}
//checking the bounds
bool Big_Bullet_2::Is_Out_Of_Bound()const
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
bool Big_Bullet_2::Is_Out_Of_Bound_Enemy()const
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
bool Big_Bullet_2::Collision_Detector(const FloatRect& Enemy_Bounds) const
{
    if (Big_Bullet1.getGlobalBounds().intersects(Enemy_Bounds) == true)
    {

        return true;
    }
}
//for clearing the bullets
void Big_Bullet_2::Bullet_Bin()
{
    Big_Bullet1.setPosition(10000, 10000);
}
//for returning bullets bounds
FloatRect Big_Bullet_2::Return_Bounds()const
{
    return Big_Bullet1.getGlobalBounds();
}

//for returning bullets cordinates
Vector2f Big_Bullet_2::Retun_Bang_Cordinates()
{
    Vector2f bang_point(Big_Bullet1.getPosition().x, Big_Bullet1.getPosition().y);

    return bang_point;
}