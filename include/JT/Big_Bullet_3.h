#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class Big_Bullet_3
{
public:
    Big_Bullet_3()
    {
        Big_Bullet2.loadFromFile("bomb.png");
        Big_Bullet1.setTexture(Big_Bullet2);

    }
    Big_Bullet_3(float initial_X, float initial_Y)
    {
        Big_Bullet2.loadFromFile("bomb.png");
        Big_Bullet1.setTexture(Big_Bullet2);
        Big_Bullet1.setPosition(initial_X, initial_Y);
        initial_x = initial_X;

        fire_speed = 0.5f;
    }

    void Big_Bullet_Move_Per();

    void Big_Bullet_Move_Per_eNEMY();

    void draw(RenderWindow& window)const;

    bool Is_Out_Of_Bound()const;

    bool Is_Out_Of_Bound_Enemy()const;

    bool Collision_Detector(const FloatRect& Enemy_Bounds) const;

    void Bullet_Bin();

    FloatRect   Return_Bounds()const;

    Vector2f Retun_Bang_Cordinates();


private:
   
    float fire_speed;
    float initial_x;

    Sprite Big_Bullet1;

    Texture Big_Bullet2;
};