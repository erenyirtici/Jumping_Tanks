#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include<vector>
#include"Bullet_3.h"
#include"Tank_3.h"
#include"Enemy_Tank_3.h"
#include"Snow_Ball_3.h"
#include"Big_Bullet_3.h"


bool Is_Banged_3 = false;
bool Is_Banged_Enemy = false;
float bang_enemyx, bang_enemyy;
float bangx_3, bangy_3;



using namespace sf;
using namespace std;

//Game over ekraný için
enum GameState_3 {
	Playing3,
	GameOver3,
	Win3,
};

class level_3
{
public:
	int play(void)
	{
		


		//Game over ekraný
		GameState_3 gameState = GameState_3::Playing3;


		
		RenderWindow window(sf::VideoMode(800, 600), "Jumping Tanks");
		
		Background.loadFromFile("background3.jpg");
		Sprite Background_Sprite(Background);

	

		RectangleShape healthBar2(Vector2f(tank2.get_Health()/8, 10));
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
		freezeTexture.loadFromFile("buz.png");
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
						
						if ((rand() % 1500 < 1) || dodge)
						{
							tank2.Jumping();
							dodge = false;
						}
						
						if (tank2.Enemy_Tank1.getPosition().x >= 469.0 && (rand() % 100 < 65)) {
							
							tank2.Move_Left();

							if (tank2.Enemy_Tank1.getPosition().x < 470.0)
								patrol = true;


						}

						
						if (rand() % 10000 < 20)
						{
							tank2.Firing_Big_Bullet();
						}

						if (tank.LocRETURN().x > 270)
						{
							Agresive_mood = true;
						}
					}

					else if ((patrol && Agresive_mood == false))
					{
						if (tank2.Enemy_Tank1.getPosition().x <= 700.0 && (rand() % 100 < 20))
						{
							tank2.Move_Right();
							if (tank2.Enemy_Tank1.getPosition().x == 700.0)
								patrol = false;

						}

						if (rand() % 10000 < 5)
						{ 
							tank2.Firing_Big_Bullet();
						}
					}
					else
					{
						if (tank2.Enemy_Tank1.getPosition().x <= 700.0)
						{
							

							tank2.Move_Right();

						}
						if (rand() % 10000 < 40)
						{
							tank2.Firing();
						}

						if (rand() % 10000 < 5)
						{
							tank2.Firing_Big_Bullet();
						}
						if (!(tank.LocRETURN().x < 290))
						{
							Agresive_mood = false;
						}
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
					else if (Event.key.code == Keyboard::T && counter_Snowball < 3 )
					{
						counter_Snowball++;
						tank.Firing_Snowball();
						dodge = true;
						
					
					}
					else if (Event.key.code == Keyboard::Y && counter_Big_Bullet < 3 )
					{
						counter_Big_Bullet ++;
						tank.Firing_Big_Bullet();
						dodge = true;
					}


				}






				//left rigt
				if (Keyboard::isKeyPressed(Keyboard::A) && tank.LocRETURN().x >= 0)
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
				tank.vertical_velocity += Gravity3::Get_Gravity();
				tank.tank.move(0, tank.vertical_velocity);
				tank.Is_Flying = !(Gravity3::Falling_End_Cont(tank.tank.getPosition().y));

				if (tank.Is_Flying == false)
				{
					tank.tank.setPosition(tank.tank.getPosition().x, 550);
				}
			}



			for (auto& bullet : tank.magazine)
			{
				bullet.Bullet_Move_Per();
				if (bullet.Collision_Detector((tank2.Return_Bounds(tank2.Enemy_Tank1))))
				{
					tank2.Taking_Damage(5);
					bullet.Bullet_Bin();
				}

			}

			for (auto& Snow_Ball1 : tank.magazine_snow)
			{
				Snow_Ball1.Snow_Ball_Move_Per();
				if (Snow_Ball1.Collision_Detector((tank2.Return_Bounds(tank2.Enemy_Tank1))))
				{
					stun = 1300;
					tank2.Taking_Damage(5);
					Snow_Ball1.Bullet_Bin();
					isFreezed = true;
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

			}
		
			for (auto& bullet : tank.baybies_magezine)
			{
				bullet.Bullet_Drop_Per();
				if (bullet.Collision_Detector((tank2.Return_Bounds(tank2.Enemy_Tank1))))
				{
					tank2.Taking_Damage(5);
					bullet.Bullet_Bin();
				}

			}



			tank.magazine.erase(remove_if(tank.magazine.begin(), tank.magazine.end(),
				[](const Bullet_3& bullet) {  return bullet.Is_Out_Of_Bound(); }),
				tank.magazine.end());

			tank.magazine_Big_Bullet.erase(remove_if(tank.magazine_Big_Bullet.begin(), tank.magazine_Big_Bullet.end(),
				[](Big_Bullet_3& bullet) {
					if (bullet.Is_Out_Of_Bound())
					{
						bangx_3 = bullet.Retun_Bang_Cordinates().x;
						bangy_3 = bullet.Retun_Bang_Cordinates().y;
						Is_Banged_3 = true;
					}
					return bullet.Is_Out_Of_Bound(); }),
				tank.magazine_Big_Bullet.end());

			tank.baybies_magezine.erase(remove_if(tank.baybies_magezine.begin(), tank.baybies_magezine.end(),
				[](const Bullet_3& bullet) {  return bullet.Is_Out_Of_Bound(); }),
				tank.baybies_magezine.end());


			if (Is_Banged_3)
			{
				tank.Droping_Baby_Bullets(bangx_3 - 40, bangy_3, 0.0);
				tank.Droping_Baby_Bullets(bangx_3 - 20, bangy_3, 0.0);
				tank.Droping_Baby_Bullets(bangx_3, bangy_3, 0.0);
				tank.Droping_Baby_Bullets(bangx_3 + 20, bangy_3, 0.0);
				tank.Droping_Baby_Bullets(bangx_3 + 40, bangy_3, 0.0);
				Is_Banged_3 = false;
			}
			RectangleShape healthBar2(Vector2f(tank2.get_Health()/8, 10));
			healthBar2.setFillColor(Color::Green);
			healthBar2.setPosition(400, 30);

			window.clear();
			window.draw(Background_Sprite);
			tank.Draw(window, tank.tank, tank.get_Health());
			tank.Draw_Snow(window);
			tank.Draw_Big_Bullet(window);
			tank.Draw_Big_Bullets_Babies(window);
			tank.Draw_Bullet(window);
			tank2.Draw_Bullet(window);
			tank2.Draw_Big_Bullet(window);
			tank2.Draw_Big_Bullets_Babies(window);
			tank2.Draw(window, tank2.Enemy_Tank1, tank2.get_Health());
			window.draw(healthBar);
			window.draw(healthBar2);

			if (isFreezed)
			{
				freezeSprite.setPosition(tank2.LocRETURN().x, tank2.LocRETURN().y);
				window.draw(freezeSprite);
			}

			if (gameState == GameState_3::GameOver3) {
				
				window.draw(gameOverText);

				// Check if 3 seconds have passed
				if (gameOverClock.getElapsedTime().asSeconds() >= 2.5) {
					gameClosed = true;

				}
			}

			if (gameState == GameState_3::Win3) {
				
				window.draw(winText);
				Win_or_Lose3 = true; 

				// Check if 3 seconds have passed
				if (winClock.getElapsedTime().asSeconds() >= 2.5) {
					gameClosed = true;

				}
			}
			window.display();

			//left rigt
			if (Keyboard::isKeyPressed(Keyboard::A) && tank.LocRETURN().x >= 0)
			{
				tank.Move_Left();
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				tank.Move_Right();
			}

			//leftright





				// Routines for enemy tank
		
			if (tank2.Is_Flying)
			{
				tank2.vertical_velocity += Gravity3::Get_Gravity();
				tank2.Enemy_Tank1.move(0, tank2.vertical_velocity);
				tank2.Is_Flying = !(Gravity3::Falling_End_ContEnemy(tank2.Enemy_Tank1.getPosition().y));

				if (tank2.Is_Flying == false)
				{
					tank2.Enemy_Tank1.setPosition(tank2.Enemy_Tank1.getPosition().x, 350);

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

			for (auto& Big_Bullet1 : tank2.magazine_Big_Bullet_enemy)
			{
				Big_Bullet1.Big_Bullet_Move_Per_eNEMY();
				if (Big_Bullet1.Collision_Detector((tank.Return_Bounds(tank.tank))))
				{
					tank.Taking_Damage(10);
					Big_Bullet1.Bullet_Bin();

				}

			}

		

			for (auto& bullet : tank2.babiesmagazinenemy)
			{

				bullet.Bullet_Drop_Per_Enemy();
				if (bullet.Collision_Detector((tank.Return_Bounds(tank.tank))))
				{

					tank.Taking_Damage(5);
					bullet.Bullet_Bin();
				}

			}

			if (Is_Banged_Enemy)
			{
				tank.Droping_Baby_Bullets(bangx_3 - 40, bangy_3, 0.0);
				tank.Droping_Baby_Bullets(bangx_3 - 20, bangy_3, 0.0);
				tank.Droping_Baby_Bullets(bangx_3, bangy_3, 0.0);
				tank.Droping_Baby_Bullets(bangx_3 + 20, bangy_3, 0.0);
				tank.Droping_Baby_Bullets(bangx_3 + 40, bangy_3, 0.0);
				Is_Banged_Enemy = false;
			}

			//left rigt
			if (Keyboard::isKeyPressed(Keyboard::A) && tank.LocRETURN().x >= 0)
			{
				tank.Move_Left();
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				tank.Move_Right();
			}
			

		

			tank2.magazine.erase(remove_if(tank2.magazine.begin(), tank2.magazine.end(),
				[](const Bullet_3& bullet) { return bullet.Is_Out_Of_Bound_Enemy(); }),
				tank2.magazine.end());

			tank2.magazine_Big_Bullet_enemy.erase(remove_if(tank2.magazine_Big_Bullet_enemy.begin(), tank2.magazine_Big_Bullet_enemy.end(),
				[](Big_Bullet_3& bullet) {
					if (bullet.Is_Out_Of_Bound_Enemy())
					{

						bang_enemyx = bullet.Retun_Bang_Cordinates().x;
						bang_enemyy = bullet.Retun_Bang_Cordinates().y;
						Is_Banged_Enemy = true;
					}
					return bullet.Is_Out_Of_Bound_Enemy(); }),
				tank2.magazine_Big_Bullet_enemy.end());

			tank2.babiesmagazinenemy.erase(remove_if(tank2.babiesmagazinenemy.begin(), tank2.babiesmagazinenemy.end(),
				[](const Bullet_3& bullet) {  return bullet.Is_Out_Of_Bound(); }),
				tank2.babiesmagazinenemy.end());

			if (Is_Banged_Enemy)
			{
				tank2.Droping_Baby_Bullets(bang_enemyx - 40, bang_enemyy, 0.0);
				tank2.Droping_Baby_Bullets(bang_enemyx - 20, bang_enemyy, 0.0);
				tank2.Droping_Baby_Bullets(bang_enemyx, bang_enemyy, 0.0);
				tank2.Droping_Baby_Bullets(bang_enemyx + 20, bang_enemyy, 0.0);
				tank2.Droping_Baby_Bullets(bang_enemyx + 40, bang_enemyy, 0.0);
				Is_Banged_Enemy = false;
			}

			if (tank.get_Health() <= 0 && gameState == GameState_3::Playing3) {
				if (!explosionShown) {
					// Show explosion for one second
					deathSprite.setPosition(tank.tank.getPosition().x - 90, tank.tank.getPosition().y - 100);
					window.draw(deathSprite);
					window.display();

					if (explosionClock.getElapsedTime().asSeconds() >= 7.5) {
						explosionShown = true;
						gameOverClock.restart(); // Start the timer for the game over screen
					}
				}
				else {
					// Transition to the game over state after showing the explosion
					gameState = GameState_3::GameOver3;
				}
			}
			if (tank2.get_Health() <= 0 && gameState == GameState_3::Playing3) {
				if (!explosionShown) {
					// Show explosion for one second
					deathSprite.setPosition(tank2.Enemy_Tank1.getPosition().x - 90, tank2.Enemy_Tank1.getPosition().y - 100);
					window.draw(deathSprite);
					window.display();

					if (explosionClock.getElapsedTime().asSeconds() >= 7.5) {
						explosionShown = true;
						winClock.restart(); // Start the timer for the game over screen
					}
				}
				else {
					// Transition to the game over state after showing the explosion
					gameState = GameState_3::Win3;
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
			tank2.Draw_Big_Bullet(window);
			tank2.Draw_Big_Bullets_Babies(window);
			tank2.Draw(window, tank2.Enemy_Tank1, tank2.get_Health());
			window.draw(healthBar);
			window.draw(healthBar2);
			if (isFreezed)
			{
				freezeSprite.setPosition(tank2.LocRETURN().x, tank2.LocRETURN().y);
				window.draw(freezeSprite);
			}

			if (gameState == GameState_3::GameOver3) {
				
				window.draw(gameOverText);

				// Check if 3 seconds have passed
				if (gameOverClock.getElapsedTime().asSeconds() >= 2.5) {
					gameClosed = true;

				}
			}

			if (gameState == GameState_3::Win3) {
			
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
		return Win_or_Lose3;
	}
	public:
		bool Win_or_Lose3=false;
	private:
		int counter_Snowball = 0;
		int counter_Big_Bullet = 0;
		int stun = 0;
		bool Agresive_mood = false; ;
		bool dodge = false;
		bool isFreezed = false;
		bool patrol = false;
		Tank_3 tank;
		Enemy_Tank_3 tank2;
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