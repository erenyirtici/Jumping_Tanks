#include<iostream>
#include"Snow_Ball_2.h"
#include<SFML/Graphics.hpp>


using namespace sf;
using namespace std;

//for moving snows
void Snow_Ball_2::Snow_Ball_Move_Per()
{
    snowball.move(fire_speed, 0);
}

//for enemy
void   Snow_Ball_2::Snow_Ball_Move_Per_eNEMY()
{
    snowball.move(-fire_speed, 0);
}
//for drawing snows
void  Snow_Ball_2::draw(RenderWindow& window)const
{
    window.draw(snowball);
}
//for controling out bound
bool  Snow_Ball_2::Is_Out_Of_Bound()const
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
//for enemy
bool  Snow_Ball_2::Is_Out_Of_Bound_Enemy()const
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
bool  Snow_Ball_2::Collision_Detector(const FloatRect& Enemy_Bounds) const
{
    if (snowball.getGlobalBounds().intersects(Enemy_Bounds) == true)
    {

        return true;
    }
}
//for clearing snows
void  Snow_Ball_2::Bullet_Bin()
{
    snowball.setPosition(10000, 10000);
}
//for returnig bullets
FloatRect  Snow_Ball_2::Return_Bounds()const
{
    return snowball.getGlobalBounds();
}
