#include<iostream>
#include"Bullet_2.h"
#include<SFML/Graphics.hpp>


using namespace sf;
using namespace std;
// for moving bullets
void  Bullet_2:: Bullet_Move_Per()
{
    bullet.move(fire_speed, 0);
}
//for dropping baby bullets
void Bullet_2::Bullet_Drop_Per()
{
    bullet.move(0, inittial_fall += Gravity2::Get_Gravity());
}
//moving bullet for enemy
void Bullet_2::Bullet_Move_Per_eNEMY()
{
    bullet.move(-fire_speed, 0);
}
//for drawing
void Bullet_2::draw(RenderWindow& window)const
{
    window.draw(bullet);
}
//controlling is out of bound
bool Bullet_2::Is_Out_Of_Bound()const
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
//contolling for enemy
bool Bullet_2::Is_Out_Of_Bound_Enemy()const
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
//for checking collision
bool Bullet_2::Collision_Detector(const FloatRect& Enemy_Bounds) const
{
    if (bullet.getGlobalBounds().intersects(Enemy_Bounds) == true)
    {

        return true;
    }
}

//for clearing bullets
void Bullet_2::Bullet_Bin()
{
    bullet.setPosition(10000, 10000);
}
