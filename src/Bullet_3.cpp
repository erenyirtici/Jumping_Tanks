#include<iostream>
#include"Bullet_3.h"
#include<SFML/Graphics.hpp>


using namespace sf;
using namespace std;
//for mooving bullets
void Bullet_3::Bullet_Move_Per()
{
    bullet.move(fire_speed, 0);
}
//for dropping bullets
void Bullet_3::Bullet_Drop_Per()
{
    bullet.move(0, inittial_fall += Gravity3::Get_Gravity());


}
//for dropping bullets of enemy
void  Bullet_3::Bullet_Drop_Per_Enemy()
{
    bullet.move(0, inittial_fall += Gravity3::Get_Gravity());
}
//bullet move per enemy
void Bullet_3::Bullet_Move_Per_eNEMY()
{
    bullet.move(-fire_speed, 0);
}
//for drawing bullets
void Bullet_3::draw(RenderWindow& window)const
{
    window.draw(bullet);
}
//for controlling out of bound 
bool Bullet_3::Is_Out_Of_Bound()const
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
bool Bullet_3::Is_Out_Of_Bound_Enemy()const
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
//for checking the collision
bool Bullet_3::Collision_Detector(const FloatRect& Enemy_Bounds) const
{
    if (bullet.getGlobalBounds().intersects(Enemy_Bounds) == true)
    {

        return true;
    }
}
//for clearing the bullets
void Bullet_3::Bullet_Bin()
{
    bullet.setPosition(10000, 10000);
}
