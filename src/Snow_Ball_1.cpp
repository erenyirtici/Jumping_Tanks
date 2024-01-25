#include<iostream>
#include"Snow_Ball_1.h"
#include<SFML/Graphics.hpp>


using namespace sf;
using namespace std;

//for moving snowball
void Snow_Ball::Snow_Ball_Move_Per()
{
    snowball.move(fire_speed, 0);
}
//for enemy
void Snow_Ball::Snow_Ball_Move_Per_eNEMY()
{
    snowball.move( -fire_speed, 0);
}
//for drawing snow
void Snow_Ball::draw(RenderWindow& window)const
{
    window.draw(snowball);
}
//for controlling bounds
bool Snow_Ball::Is_Out_Of_Bound()const
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
bool Snow_Ball::Is_Out_Of_Bound_Enemy()const
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
//for checking detection of swonball
bool Snow_Ball::Collision_Detector(const FloatRect& Enemy_Bounds) const
{
    if (snowball.getGlobalBounds().intersects(Enemy_Bounds) == true)
    {

        return true;
    }
}
//for clearing snow
void Snow_Ball::Bullet_Bin()
{
    snowball.setPosition(10000, 10000);
}
//for returning bounds
FloatRect Snow_Ball::Return_Bounds()const
{
    return snowball.getGlobalBounds();
}
