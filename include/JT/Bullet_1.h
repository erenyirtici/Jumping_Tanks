#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Gravity_1.h"

using namespace sf;
using namespace std;

class Bullet
{
public:
    Bullet()
    {
        bullet.setSize(Vector2f(10.0f, 5.0f));
        bullet.setFillColor(Color::Black);

    }
    Bullet(float initial_X, float initial_Y)
    {
        bullet.setSize(Vector2f(10.0f, 5.0f));
        bullet.setFillColor(Color::Black);
        bullet.setPosition(initial_X, initial_Y);
        initial_x = initial_X;

        fire_speed = 1.0f;
    }

    Bullet(float initial_X, float initial_Y, int drop_velocity)
    {
        bullet.setSize(Vector2f(5.0f, 5.0f));
        bullet.setFillColor(Color::Red);
        bullet.setPosition(initial_X, initial_Y);
        initial_x = initial_X;

        fire_speed = drop_velocity;
    }
    void Bullet_Move_Per();

    void Bullet_Drop_Per();

    void Bullet_Move_Per_eNEMY();
    
    void draw(RenderWindow& window)const;

    bool Is_Out_Of_Bound()const;

    bool Is_Out_Of_Bound_Enemy()const;

    bool Collision_Detector(const FloatRect& Enemy_Bounds) const;

    void Bullet_Bin();

private:
    RectangleShape  bullet;

    float fire_speed;
    float initial_x;
    float inittial_fall = 0.0;

};