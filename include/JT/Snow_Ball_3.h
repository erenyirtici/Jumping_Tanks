#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Snow_Ball_3
{
public:
    Snow_Ball_3()
    {
         snowball_Texture.loadFromFile("snowball.png");
        snowball.setTexture(snowball_Texture);

    }
    Snow_Ball_3(float initial_X, float initial_Y)
    {
        snowball_Texture.loadFromFile("snowball.png");
        snowball.setTexture(snowball_Texture);
        snowball.setPosition(initial_X, initial_Y);
        initial_x = initial_X;

        fire_speed = 0.5f;
    }

    void Snow_Ball_Move_Per();
   

    void Snow_Ball_Move_Per_eNEMY();
   
    void draw(RenderWindow& window)const;
   
    bool Is_Out_Of_Bound()const;
    
    bool Is_Out_Of_Bound_Enemy()const;

    bool Collision_Detector(const FloatRect& Enemy_Bounds) const;
   
    void Bullet_Bin();
   
    FloatRect Return_Bounds()const;

private:
  
    float fire_speed;
    float initial_x;

    Sprite snowball;

    Texture snowball_Texture;
};