#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Snow_Ball_3.h"

using namespace sf;
using namespace std;

//for moving bullets
void  Snow_Ball_3:: Snow_Ball_Move_Per()
{
    snowball.move(fire_speed, 0);
}
//for enemy
void Snow_Ball_3::Snow_Ball_Move_Per_eNEMY()
{
    snowball.move(-fire_speed, 0);
}
//for drawing
void Snow_Ball_3::draw(RenderWindow& window)const
{
    window.draw(snowball);
}


//for controlling out of bound
bool Snow_Ball_3::Is_Out_Of_Bound()const
{

    if ((snowball.getPosition().x) - (initial_x) > 800)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// for enemy
bool Snow_Ball_3::Is_Out_Of_Bound_Enemy()const
{

    if ((initial_x)-(snowball.getPosition().x) > 800)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//for checking collision
bool Snow_Ball_3::Collision_Detector(const FloatRect& Enemy_Bounds) const
{
    if (snowball.getGlobalBounds().intersects(Enemy_Bounds) == true)
    {

        return true;
    }
}
// for clearing bullets
void Snow_Ball_3::Bullet_Bin()
{
    snowball.setPosition(10000, 10000);
}
//for returning bounds
FloatRect Snow_Ball_3::Return_Bounds()const
{
    return snowball.getGlobalBounds();
}
