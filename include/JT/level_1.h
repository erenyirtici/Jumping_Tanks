#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include<vector>
#include"Bullet_1.h"
#include"Tank_1.h"
#include"Enemy_Tank_1.h"
#include"Snow_Ball_1.h"
#include"Big_Bullet_1.h"
#include"Gravity_1.h"

bool Is_Banged = false;
float bangx, bangy;


using namespace sf;
using namespace std;

//Game over ekraný için
enum GameState {
	Playing,
	GameOver,
	Win,
};


class level_1
{
public:
	int play(void)
	{
		
	

		//Game over ekraný
		GameState gameState = GameState::Playing;


		
		RenderWindow window(sf::VideoMode(800, 600), "Jumping Tanks");
		
		Background.loadFromFile("background2.jpg");
		Sprite Background_Sprite(Background);
		

		

		



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


			Event Event;

			while (window.pollEvent(Event))
			{
				dodge = false;
				if (Event.type == Event::Closed)
					window.close();

				if (Event.type == Event::KeyPressed)
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
					else if (Event.key.code == Keyboard::T && counter_Snowball < 2)
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

				if (stun <= 0)
				{
					isFreezed = false;
					if (tank2.get_Health())
					{
						if (tank2.get_Health() < 50) {
							
							Agresive_mood = false;
						}


						if (Agresive_mood) {
							
							if (tank2.tank.getPosition().x > 327.0) {
								
								tank2.Move_Left();
								tank2.Move_Left();
								tank2.Move_Left();
								tank2.Move_Left();
								tank2.Move_Left();
								tank2.Move_Left();
							}

							
							{
								tank2.Firing();
							}
						}
						else {
							if (tank2.tank.getPosition().x < 700.0) {
								tank2.Move_Right();
								tank2.Move_Right();
								tank2.Move_Right();
								tank2.Move_Right();
								tank2.Move_Right();
								tank2.Move_Right();
							}

							if (rand() % 100 < 20) {
								tank2.Firing();
							}
						}

					
						if ((rand() % 100 < 5) || dodge) { 
							tank2.Jumping();
						}


					}

				}
				else
				{

					stun--;
				}




				//left right
				if (Keyboard::isKeyPressed(Keyboard::A))
				{
					tank.Move_Left();
				}

				if (Keyboard::isKeyPressed(Keyboard::D))
				{
					tank.Move_Right();
				}

			


			}
			//Routines for our tank

			RectangleShape healthBar(Vector2f(tank.get_Health(), 10));
			healthBar.setFillColor(Color::Green);
			healthBar.setPosition(60, 30);

			if (tank.Is_Flying)
			{
				tank.vertical_velocity += Gravity1::Get_Gravity();
				tank.tank.move(0, tank.vertical_velocity);
				tank.Is_Flying = !(Gravity1::Falling_End_Cont(tank.tank.getPosition().y));

				if (tank.Is_Flying == false)
				{
					tank.tank.setPosition(tank.tank.getPosition().x, 550);
				}
			}



			for (auto& bullet : tank.magazine)
			{
				bullet.Bullet_Move_Per();
				if (bullet.Collision_Detector((tank2.Do_Return_Bounds(tank2))))
				{
					tank2.Taking_Damage(5);
					bullet.Bullet_Bin();
				}

			}

			for (auto& Snow_Ball1 : tank.magazine_snow)
			{
				Snow_Ball1.Snow_Ball_Move_Per();
				if (Snow_Ball1.Collision_Detector((tank2.Do_Return_Bounds(tank2))))
				{
					stun = 100;
					tank2.Taking_Damage(5);
					Snow_Ball1.Bullet_Bin();
					isFreezed = true;

				}

			}

			for (auto& Big_Bullet1 : tank.magazine_Big_Bullet)
			{
				Big_Bullet1.Big_Bullet_Move_Per();
				if (Big_Bullet1.Collision_Detector((tank2.Do_Return_Bounds(tank2))))
				{
					tank2.Taking_Damage(1);
					Big_Bullet1.Bullet_Bin();
				}

			}
			
			for (auto& bullet : tank.baybies_magezine)
			{
				bullet.Bullet_Drop_Per();
				if (bullet.Collision_Detector((tank2.Do_Return_Bounds(tank2))))
				{
					tank2.Taking_Damage(5);
					bullet.Bullet_Bin();
				}

			}



			tank.magazine.erase(remove_if(tank.magazine.begin(), tank.magazine.end(),
				[](const Bullet& bullet) {  return bullet.Is_Out_Of_Bound(); }),
				tank.magazine.end());

			tank.magazine_Big_Bullet.erase(remove_if(tank.magazine_Big_Bullet.begin(), tank.magazine_Big_Bullet.end(),
				[](Big_Bullet& bullet) {
					if (bullet.Is_Out_Of_Bound())
					{

						bangx = bullet.Retun_Bang_Cordinates().x;
						bangy = bullet.Retun_Bang_Cordinates().y;
						Is_Banged = true;
					}
					return bullet.Is_Out_Of_Bound(); }),
				tank.magazine_Big_Bullet.end());

			tank.baybies_magezine.erase(remove_if(tank.baybies_magezine.begin(), tank.baybies_magezine.end(),
				[](const Bullet& bullet) {  return bullet.Is_Out_Of_Bound(); }),
				tank.baybies_magezine.end());


			if (Is_Banged)
			{
				tank.Droping_Baby_Bullets(bangx - 40, bangy, 0.0);
				tank.Droping_Baby_Bullets(bangx - 20, bangy, 0.0);
				tank.Droping_Baby_Bullets(bangx, bangy, 0.0);
				tank.Droping_Baby_Bullets(bangx + 20, bangy, 0.0);
				tank.Droping_Baby_Bullets(bangx + 40, bangy, 0.0);
				Is_Banged = false;
			}
			RectangleShape healthBar2(Vector2f(tank2.get_Health(), 10));
			healthBar2.setFillColor(Color::Green);
			healthBar2.setPosition(600, 30);

			window.clear();
			window.draw(Background_Sprite);
			tank.Draw(window, tank.tank, tank.get_Health());
			tank.Draw_Snow(window);
			tank.Draw_Big_Bullet(window);
			tank.Draw_Big_Bullets_Babies(window);
			tank.Draw_Bullet(window);
			tank2.Draw_Bullet(window);
			tank2.Draw(window, tank2.tank, tank2.get_Health());
			window.draw(healthBar);
			window.draw(healthBar2);
			

			if (isFreezed)
			{
				freezeSprite.setPosition(tank2.LocRETURN().x, tank2.LocRETURN().y);
				window.draw(freezeSprite);
			}

			if (gameState == GameState::GameOver) {
			
				window.draw(gameOverText);

				// Check if 3 seconds have passed
				if (gameOverClock.getElapsedTime().asSeconds() >= 2.5) {
					gameClosed = true;

				}
			}

			if (gameState == GameState::Win) {
				
				window.draw(winText);
				

				// Check if 3 seconds have passed
				if (winClock.getElapsedTime().asSeconds() >= 2.5) {
					gameClosed = true;

				}
			}

			window.display();

			//left rigt
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				tank.Move_Left();
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				tank.Move_Right();
			}

			





			// Routines for enemy tank

		
			if (tank2.Is_Flying)
			{
				tank2.vertical_velocity += Gravity1::Get_Gravity();
				tank2.tank.move(0, tank2.vertical_velocity);
				tank2.Is_Flying = !(Gravity1::Falling_End_Cont(tank2.tank.getPosition().y));

				if (tank2.Is_Flying == false)
				{
					tank2.tank.setPosition(tank2.tank.getPosition().x, 550);

				}
			}



			for (auto& bullet : tank2.magazine)
			{
				bullet.Bullet_Move_Per_eNEMY();
				if (bullet.Collision_Detector((tank.Do_Return_Bounds(tank))))
				{
					tank.Taking_Damage(5);
					bullet.Bullet_Bin();
				}

			}




			//left rigt
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				tank.Move_Left();
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				tank.Move_Right();
			}
			


			tank2.magazine.erase(remove_if(tank2.magazine.begin(), tank2.magazine.end(),
				[](const Bullet& bullet) { return bullet.Is_Out_Of_Bound_Enemy(); }),
				tank2.magazine.end());


			if (tank.get_Health() <= 0 && gameState == GameState::Playing) {
				if (!explosionShown) {
					// Show explosion for one second
					deathSprite.setPosition(tank.tank.getPosition().x, tank.tank.getPosition().y - 65);
					window.draw(deathSprite);
					window.display();

					if (explosionClock.getElapsedTime().asSeconds() >= 7.5) {
						explosionShown = true;
						gameOverClock.restart(); // Start the timer for the game over screen
					}
				}
				else {
					// Transition to the game over state after showing the explosion
					gameState = GameState::GameOver;
				}
			}

			if (tank2.get_Health() <= 0 && gameState == GameState::Playing) {
				if (!explosionShown) {
					// Show explosion for one second
					deathSprite.setPosition(tank2.tank.getPosition().x - 75, tank2.tank.getPosition().y - 65);
					window.draw(deathSprite);
					window.display();

					if (explosionClock.getElapsedTime().asSeconds() >= 7.5) {
						explosionShown = true;
						winClock.restart(); // Start the timer for the game over screen
					}
				}
				else {
					// Transition to the game over state after showing the explosion
					gameState = GameState::Win;
				}
			}

			window.clear();
			window.draw(Background_Sprite);
			tank.Draw(window, tank.tank, tank.get_Health());
			tank.Draw_Snow(window);
			tank.Draw_Big_Bullet(window);
			tank.Draw_Big_Bullets_Babies(window);
			tank.Draw_Bullet(window);
			tank2.Draw_Bullet(window);
			tank2.Draw(window, tank2.tank, tank2.get_Health());
			window.draw(healthBar);
			window.draw(healthBar2);

			if (isFreezed)
			{
				freezeSprite.setPosition(tank2.LocRETURN().x, tank2.LocRETURN().y);
				window.draw(freezeSprite);
			}

			if (gameState == GameState::GameOver) {
				
				window.draw(gameOverText);

				// Check if 3 seconds have passed
				if (gameOverClock.getElapsedTime().asSeconds() >= 2.5) {
					gameClosed = true;

				}
			}

			if (gameState == GameState::Win) {
				window.draw(winText);
				Win_or_Lose = true;
				// Check if 3 seconds have passed
				if (winClock.getElapsedTime().asSeconds() >= 2.5) {
					gameClosed = true;

				}
			}

			window.display();




		}

		return 0;

	}

	
public:
	bool Win_or_Lose=false; 
private:
	Tank tank;
	Enemy_Tank tank2;
	int counter_Snowball = 0;
	int counter_Big_Bullet = 0;
	int stun = 0;
	bool Agresive_mood = true;
	bool dodge = false;
	bool isFreezed = false;
	Texture Background;
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