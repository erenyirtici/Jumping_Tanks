#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include<vector>
#include"Bullet_2.h"
#include"Tank_2.h"
#include"Enemy_Tank_2.h"
#include"Snow_Ball_2.h"
#include"Big_Bullet_2.h"


bool Is_Banged_2 = false;
float bangx_2, bangy_2;


using namespace sf;
using namespace std;

//Game over ekraný için
enum GameState_2 {
	Playing2,
	GameOver2,
	Win2,
};

class level_2
{
public:
	int play(void)
	{
		
		RenderWindow window(sf::VideoMode(800, 600), "Jumping Tanks");
		

		Background.loadFromFile("level2_back.jpg");
		Sprite Background_Sprite(Background);
	

		wall_texture.loadFromFile("wall1.png");
		wall1.setTexture(wall_texture);
		wall1.setPosition(270, 350);

		

		RectangleShape healthBar2(Vector2f(tank2.get_Health(), 10));
		healthBar2.setFillColor(Color::Green);
		healthBar2.setPosition(400, 30);


		font.loadFromFile("arial.ttf");
		font2.loadFromFile("arial.ttf");


		if (!font.loadFromFile("arial.ttf"))
		{
			cerr << "Font yuklenemedi!" << endl;
			// Hata durumu
		}
		// Game Over
		gameOverText.setFont(font);
		gameOverText.setCharacterSize(50);
		gameOverText.setFillColor(sf::Color::Red);
		gameOverText.setString("Game Over");
		gameOverText.setPosition(260, 180);

		//Win

		winText.setFont(font2);
		winText.setCharacterSize(50);
		winText.setFillColor(sf::Color::Green);
		winText.setString("WIN");
		winText.setPosition(360, 180);


		//Explosion
		deathTexture.loadFromFile("explosion.png");
		deathSprite.setTexture(deathTexture);
		deathSprite.setPosition(200, 250);


		//Freeze
		freezeTexture.loadFromFile("freeze.png");
		freezeSprite.setTexture(freezeTexture);
		//freezeSprite.setPosition(200, 250);


		//Timer for game over screen
		Clock gameOverClock;
		Clock winClock;
		bool gameClosed = false;


		while (window.isOpen() && !gameClosed)
		{




			if (stun <= 0)
			{
				isFreezed = false;
				if (tank2.get_Health() > 0)
				{



					if (patrol == false && Agresive_mood == false)

					{
						
						if (tank2.Enemy_Tank1.getPosition().x >= 479.0 && (rand() % 100 < 10)) {
							
							tank2.Move_Left();

							if (tank2.Enemy_Tank1.getPosition().x < 485.0)
								patrol = true;


						}

					
						if (rand() % 10000 < 20)
						{
							tank2.Firing_Snowball();
						}

						if (tank.LocRETURN().x > 200 )
						{
							Agresive_mood = true;
						}
					}

					else if ((patrol && Agresive_mood == false))
					{
						if (tank2.Enemy_Tank1.getPosition().x <= 700.0 && (rand() % 100 < 10))
						{
							tank2.Move_Right();
							if (tank2.Enemy_Tank1.getPosition().x == 700.0)
								patrol = false;

						}

						if (rand() % 10000 < 20)
						{
							tank2.Firing_Snowball();
						}
					}
					else
					{
						if (tank2.Enemy_Tank1.getPosition().x <= 700.0)
						{
							
							if ((rand() % 100 < 30) || dodge)
							{
								tank2.Jumping();
								dodge = false;
							}

							tank2.Move_Right();

							if (rand() % 100 < 20)
							{
								tank2.Firing_Snowball();
							}


						}
						if (rand() % 10000 < 25)
						{
							tank2.Firing_Snowball();
						}
						if (!(tank.LocRETURN().x > 283 && tank.LocRETURN().y < 360))
						{
							Agresive_mood = false;
						}
					}


				
					if ((rand() % 1500 < 1) || dodge)
					{ 
						tank2.Jumping();
						dodge = false;
					}


				}

			}
			else
			{
				stun--;
			}


			Event Event;

			while (window.pollEvent(Event))
			{



				if (Event.type == Event::Closed)
					window.close();

				if ((Event.type == Event::KeyPressed) && stun_enemey <= 0)
				{
					if (Event.key.code == Keyboard::W)
					{
						tank.Jumping();
					}
					else if (Event.key.code == Keyboard::F)
					{
						tank.Firing();
						dodge = true;
					}
					else if (Event.key.code == Keyboard::T && counter_Snowball < 2 )
					{
						counter_Snowball++; 
						tank.Firing_Snowball();
						dodge = true;
					}
					else if (Event.key.code == Keyboard::Y && counter_Big_Bullet < 2)
					{
						counter_Big_Bullet++; 
						tank.Firing_Big_Bullet();
						dodge = true;
					}
				}
				else
				{
					stun_enemey--;
				}






				//left rigt
				if (Keyboard::isKeyPressed(Keyboard::A) && stun_enemey <= 0)
				{
					if (tank.LocRETURN().x <= 224 || tank.LocRETURN().y < 370 || tank.LocRETURN().x > 480)
					{
						tank.Move_Left();
					}

				}

				if ((Keyboard::isKeyPressed(Keyboard::D)) && stun_enemey <= 0)
				{

					if (tank.LocRETURN().x < 221.398 || tank.LocRETURN().y < 370 || tank.LocRETURN().x > 470)
					{
						tank.Move_Right();
					}
				}



			}
			//Routines for our tank

			RectangleShape healthBar(Vector2f(tank.get_Health(), 10));
			healthBar.setFillColor(Color::Green);
			healthBar.setPosition(60, 30);
			if ((tank.LocRETURN().x < 270.0 || tank.LocRETURN().x > 492))
			{
				if (tank.Is_Flying)
				{
					tank.vertical_velocity += Gravity2::Get_Gravity();
					tank.tank.move(0, tank.vertical_velocity);
					tank.Is_Flying = !(Gravity2::Falling_End_Cont(tank.tank.getPosition().y));

					if (tank.Is_Flying == false)
					{
						tank.tank.setPosition(tank.tank.getPosition().x, 550);
					}
				}

			}
			else
			{
				if (tank.Is_Flying)
				{
					tank.vertical_velocity += Gravity2::Get_Gravity();
					tank.tank.move(0, tank.vertical_velocity);
					tank.Is_Flying = !(Gravity2::Falling_End_Cont_On_Box(tank.tank.getPosition().y));

					if (tank.Is_Flying == false)
					{
						if (tank.LocRETURN().x > 250.0 && (tank.LocRETURN().x < 450))
							tank.tank.setPosition(tank.tank.getPosition().x, 360);
						above = true;
					}
				}

			}
			if ((tank.LocRETURN().x < 221.398 || tank.LocRETURN().x > 492) && above)
			{
				tank.Is_Flying = true;
				above = false;
			}






			for (auto& bullet : tank.magazine)
			{
				bullet.Bullet_Move_Per();
				if (bullet.Collision_Detector((tank2.Return_Bounds(tank2.Enemy_Tank1))))
				{
					tank2.Taking_Damage(5);
					bullet.Bullet_Bin();
				}
				if (bullet.Collision_Detector((wall1.getGlobalBounds())))
				{
					bullet.Bullet_Bin();
				}

			}

			for (auto& Snow_Ball1 : tank.magazine_snow)
			{
				Snow_Ball1.Snow_Ball_Move_Per();
				if (Snow_Ball1.Collision_Detector((tank2.Return_Bounds(tank2.Enemy_Tank1))))
				{
					stun = 10000;
					tank2.Taking_Damage(5);
					Snow_Ball1.Bullet_Bin();
					isFreezed = true;
				}

				if (Snow_Ball1.Collision_Detector((wall1.getGlobalBounds())))
				{
					Snow_Ball1.Bullet_Bin();
				}

			}

			for (auto& Big_Bullet1 : tank.magazine_Big_Bullet)
			{
				Big_Bullet1.Big_Bullet_Move_Per();
				if (Big_Bullet1.Collision_Detector((tank2.Return_Bounds(tank2.Enemy_Tank1))))
				{
					tank2.Taking_Damage(1);
					Big_Bullet1.Bullet_Bin();
				}

				if (Big_Bullet1.Collision_Detector((wall1.getGlobalBounds())))
				{
					Big_Bullet1.Bullet_Bin();
				}

			}
			
			for (auto& bullet : tank.baybies_magezine)
			{
				bullet.Bullet_Drop_Per();
				if (bullet.Collision_Detector((tank2.Return_Bounds(tank2.Enemy_Tank1))))
				{
					tank2.Taking_Damage(5);
					bullet.Bullet_Bin();
				}

				if (bullet.Collision_Detector((wall1.getGlobalBounds())))
				{
					bullet.Bullet_Bin();
				}

			}








			tank.magazine.erase(remove_if(tank.magazine.begin(), tank.magazine.end(),
				[](const Bullet_2& bullet) {  return bullet.Is_Out_Of_Bound(); }),
				tank.magazine.end());

			tank.magazine_Big_Bullet.erase(remove_if(tank.magazine_Big_Bullet.begin(), tank.magazine_Big_Bullet.end(),
				[](Big_Bullet_2& bullet) {
					if (bullet.Is_Out_Of_Bound())
					{

						bangx_2 = bullet.Retun_Bang_Cordinates().x;
						bangy_2 = bullet.Retun_Bang_Cordinates().y;
						Is_Banged_2 = true;
					}
					return bullet.Is_Out_Of_Bound(); }),
				tank.magazine_Big_Bullet.end());

			tank.baybies_magezine.erase(remove_if(tank.baybies_magezine.begin(), tank.baybies_magezine.end(),
				[](const Bullet_2& bullet) {  return bullet.Is_Out_Of_Bound(); }),
				tank.baybies_magezine.end());

			tank.magazine_snow.erase(remove_if(tank.magazine_snow.begin(), tank.magazine_snow.end(),
				[](const Snow_Ball_2& bullet) {  return bullet.Is_Out_Of_Bound(); }),
				tank.magazine_snow.end());


			if (Is_Banged_2)
			{
				tank.Droping_Baby_Bullets(bangx_2 - 40, bangy_2, 0.0);
				tank.Droping_Baby_Bullets(bangx_2 - 20, bangy_2, 0.0);
				tank.Droping_Baby_Bullets(bangx_2, bangy_2, 0.0);
				tank.Droping_Baby_Bullets(bangx_2 + 20, bangy_2, 0.0);
				tank.Droping_Baby_Bullets(bangx_2 + 40, bangy_2, 0.0);
				Is_Banged_2 = false;
			}
			RectangleShape healthBar2(Vector2f(tank2.get_Health(), 10));
			healthBar2.setFillColor(Color::Green);
			healthBar2.setPosition(600, 30);

			window.clear();
			window.draw(Background_Sprite);
			tank.Draw(window, tank.tank, tank.get_Health());
			tank.Draw_Bullet(window);
			tank.Draw_Snow(window);
			tank2.Draw_Snow(window);
			tank.Draw_Big_Bullet(window);
			tank.Draw_Big_Bullets_Babies(window);
			tank2.Draw(window, tank2.Enemy_Tank1, tank2.get_Health());
			window.draw(wall1);
			window.draw(healthBar);
			window.draw(healthBar2);


			if (isFreezed)
			{
				freezeSprite.setPosition(tank2.LocRETURN().x, tank2.LocRETURN().y);
				window.draw(freezeSprite);
			}

			if (gameState == GameState_2::GameOver2) {
				
				window.draw(gameOverText);

				// Check if 3 seconds have passed
				if (gameOverClock.getElapsedTime().asSeconds() >= 2.5) {
					gameClosed = true;

				}
			}

			if (gameState == GameState_2::Win2) {
				
				window.draw(winText);
				Win_or_Lose2 = true;

				// Check if 3 seconds have passed
				if (winClock.getElapsedTime().asSeconds() >= 2.5) {
					gameClosed = true;

				}
			}

			window.display();

			//left rigt
			if (Keyboard::isKeyPressed(Keyboard::A) && stun_enemey <= 0)
			{
				if (tank.LocRETURN().x <= 224 || tank.LocRETURN().y < 370 || tank.LocRETURN().x > 480)
				{
					tank.Move_Left();
				}

			}

			if ((Keyboard::isKeyPressed(Keyboard::D)) && stun_enemey <= 0)
			{

				if (tank.LocRETURN().x < 221.398 || tank.LocRETURN().y < 370 || tank.LocRETURN().x > 470)
				{
					tank.Move_Right();
				}
			}

			//leftright





				// Routines for enemy tank
		

			if (tank2.Is_Flying)
			{
				tank2.vertical_velocity += Gravity2::Get_Gravity();
				tank2.Enemy_Tank1.move(0, tank2.vertical_velocity);
				tank2.Is_Flying = !(Gravity2::Falling_End_Cont(tank2.Enemy_Tank1.getPosition().y));

				if (tank2.Is_Flying == false)
				{
					tank2.Enemy_Tank1.setPosition(tank2.Enemy_Tank1.getPosition().x, 550);

				}
			}



			for (auto& bullet : tank2.magazine)
			{
				bullet.Bullet_Move_Per_eNEMY();
				if (bullet.Collision_Detector((tank.Return_Bounds(tank.tank))))
				{
					tank.Taking_Damage(5);
					bullet.Bullet_Bin();
				}

			}

			for (auto& Snow_Ball1 : tank2.magazine_snow)
			{
				Snow_Ball1.Snow_Ball_Move_Per_eNEMY();
				if (Snow_Ball1.Collision_Detector((tank.Return_Bounds(tank.tank))))
				{
					stun_enemey = 50;
					tank.Taking_Damage(5);
					Snow_Ball1.Bullet_Bin();
				}

				if (Snow_Ball1.Collision_Detector((wall1.getGlobalBounds())))
				{
					Snow_Ball1.Bullet_Bin();

				}

			}




			for (auto& bullet : tank.magazine)
			{
				bullet.Bullet_Move_Per();
				if (bullet.Collision_Detector((tank2.Return_Bounds(tank.tank))))
				{
					stun = 100;
					tank2.Taking_Damage(5);
					bullet.Bullet_Bin();
				}

			}



			//left rigt
			if (Keyboard::isKeyPressed(Keyboard::A) && stun_enemey <= 0)
			{
				if (tank.LocRETURN().x <= 224 || tank.LocRETURN().y < 370 || tank.LocRETURN().x > 480)
				{
					tank.Move_Left();
				}

			}

			if ((Keyboard::isKeyPressed(Keyboard::D)) && stun_enemey <= 0)
			{

				if (tank.LocRETURN().x < 221.398 || tank.LocRETURN().y < 370 || tank.LocRETURN().x > 470)
				{
					tank.Move_Right();
				}
			}
			//leftright


			tank2.magazine.erase(remove_if(tank2.magazine.begin(), tank2.magazine.end(),
				[](const Bullet_2& bullet) { return bullet.Is_Out_Of_Bound_Enemy(); }),
				tank2.magazine.end());

			tank2.magazine_snow.erase(remove_if(tank2.magazine_snow.begin(), tank2.magazine_snow.end(),
				[](const Snow_Ball_2& bullet) {  return bullet.Is_Out_Of_Bound(); }),
				tank2.magazine_snow.end());

			if (tank.get_Health() <= 0 && gameState == GameState_2::Playing2) {
				if (!explosionShown) {
					// Show explosion for one second
					deathSprite.setPosition(tank.tank.getPosition().x - 90, tank.tank.getPosition().y - 70);
					window.draw(deathSprite);
					window.display();

					if (explosionClock.getElapsedTime().asSeconds() >= 7.5) {
						explosionShown = true;
						gameOverClock.restart(); // Start the timer for the game over screen
					}
				}
				else {
					// Transition to the game over state after showing the explosion
					gameState = GameState_2::GameOver2;
				}
			}

			if (tank2.get_Health() <= 0 && gameState == GameState_2::Playing2) {
				if (!explosionShown) {
					// Show explosion for one second
					deathSprite.setPosition(tank2.LocRETURN().x - 90, tank2.LocRETURN().y - 70);
					window.draw(deathSprite);
					window.display();

					if (explosionClock.getElapsedTime().asSeconds() >= 7.5) {
						explosionShown = true;
						winClock.restart(); // Start the timer for the game over screen
					}
				}
				else {
					// Transition to the game over state after showing the explosion
					gameState = GameState_2::Win2;
				}
			}


			window.clear();
			window.draw(Background_Sprite);
			tank.Draw(window, tank.tank, tank.get_Health());
			tank.Draw_Bullet(window);
			tank.Draw_Snow(window);
			tank2.Draw_Snow(window);
			tank.Draw_Big_Bullet(window);
			tank.Draw_Big_Bullets_Babies(window);
			tank2.Draw(window, tank2.Enemy_Tank1, tank2.get_Health());
			window.draw(wall1);
			window.draw(healthBar);
			window.draw(healthBar2);

			if (isFreezed)
			{
				freezeSprite.setPosition(tank2.LocRETURN().x, tank2.LocRETURN().y);
				window.draw(freezeSprite);
			}

			if (gameState == GameState_2::GameOver2) {
				
				window.draw(gameOverText);

				// Check if 3 seconds have passed
				if (gameOverClock.getElapsedTime().asSeconds() >= 2.5) {
					gameClosed = true;

				}
			}

			if (gameState == GameState_2::Win2) {
			
				window.draw(winText);

				// Check if 3 seconds have passed
				if (winClock.getElapsedTime().asSeconds() >= 2.5) {
					gameClosed = true;

				}
			}

			window.display();




		}

		return 0;

	}

	bool Win_Lose()
	{
		return Win_or_Lose2;
	}
	public:
		bool Win_or_Lose2 = false;

	private:
		int counter_Snowball = 0;
		int counter_Big_Bullet = 0;
		int stun = 0;
		int stun_enemey = 0;
		bool Agresive_mood = false;
		bool dodge = false;

		bool above = false;
		bool patrol = false;

		bool isFreezed = false;

		Tank_2 tank;
		Enemy_Tank_2 tank2;

		Texture Background;
		Sprite wall1;

		Texture wall_texture;
		//Game over ekraný
		GameState_2 gameState = GameState_2::Playing2;

		//for explosion
		Texture deathTexture;
		Sprite deathSprite;

		Clock explosionClock;
		bool explosionShown = false;

		//for freeze 
		Texture freezeTexture;
		Sprite freezeSprite;


		//For Game over screen 
		Font font;
		Text gameOverText;

		//For WIN screen
		Font font2;
		Text winText;
};