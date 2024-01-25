#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "MainMenu.h"
#include"Game_Engine.h"


using namespace std;
using namespace sf;

int main() {
    //Opening a Window
    RenderWindow window(VideoMode(800, 600), "JUMPING TANKS");
    
   //Assign initial MenuState
    MenuState menuState = MenuState::Play;
    //Texture font and musics
    Texture backgroundTexture;
    Font font;
    Music music1;
    Music music2;
    //Checking music and background files
    if (!music1.openFromFile("music1.ogg"))
        return -1;
    if (!music2.openFromFile("music2.ogg"))
        return -1;
    music1.play();
    if (!backgroundTexture.loadFromFile("backgroundm.jpg")) {
        cerr << "Failed to load background texture." << endl;
        return -1; 
    }

    //Import icon files
    Sprite backgroundSprite(backgroundTexture);
    OptionsState optionsState;
    optionsState.getIconTextureOn().loadFromFile("ikon1.png");
    optionsState.getIconTextureOff().loadFromFile("ikon2.png");
    
    
   
    
    //Window functions
    while (window.isOpen()) {
        Event event;
        if (optionsState.isMusicEnabled() == false) {
            music1.stop();
            music2.stop();
        }
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed){
                window.close();
            }
            //Menustate updates based on user selection
            else if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Up) {
                    if (menuState == MenuState::Play) {
                        menuState = MenuState::Exit;
                    }
                    else if (menuState == MenuState::Options) {
                        menuState = MenuState::Play;
                    }
                    else if (menuState == MenuState::Producers) {
                        menuState = MenuState::Options;
                    }
                    else if (menuState == MenuState::Controls) {
                        menuState = MenuState::Producers;
                    }
                    else {
                        menuState = MenuState::Controls;
                    }
                }
                else if (event.key.code == Keyboard::Down) {
                    if (menuState == MenuState::Play) {
                        menuState = MenuState::Options;
                    }
                    else if (menuState == MenuState::Options) {
                        menuState = MenuState::Producers;
                    }
                    else if (menuState == MenuState::Producers) {
                        menuState = MenuState::Controls;
                    }
                    else if (menuState == MenuState::Controls) {
                        menuState = MenuState::Exit;
                    }
                    else {
                        menuState = MenuState::Play;
                    }
                }
                else if (event.key.code == Keyboard::Enter) {
                    if (menuState == MenuState::Play) {
                        //Game start
                        Game_Engine game_Start;
                        cout << "Play selected!" << endl;
                        music1.stop();
                        music2.play();

                        game_Start.Game();
                        music2.stop();
                        music1.play();

                        
                    }
                    else if (menuState == MenuState::Options) {

                       //Option selection functions
                        cout << "Options selected!" << endl;
                        
                        RenderWindow optionsWindow(VideoMode(800, 600), "Options", Style::Close);
                        handleOptions(optionsWindow, optionsState);
                        
                        
                        //Window functions and loading some files
                        while (optionsWindow.isOpen()) {
                            Event optionsEvent;
                            while (optionsWindow.pollEvent(optionsEvent)) {
                                if (optionsEvent.type == Event::Closed) {
                                    optionsWindow.close();
                                }
                            }
                            optionsWindow.clear();
                            
                            if (font.loadFromFile("arial.ttf")) {
                                Text musicText("Music", font, 30);
                                musicText.setPosition(300.0f, 250.0f);
                                optionsWindow.clear();

                                Texture optionsBackgroundTexture;
                                if (optionsBackgroundTexture.loadFromFile("background1m.jpg")) {
                                    Sprite optionsBackgroundSprite(optionsBackgroundTexture);
                                    optionsWindow.draw(optionsBackgroundSprite);
                                }
                                optionsWindow.draw(musicText);
                                optionsWindow.draw(optionsState.getIconSprite());
                                optionsWindow.display();
                            }
                            //Return function for esc key
                            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                                optionsWindow.close();
                            }

                            Texture optionsBackgroundTexture;
                            if (optionsBackgroundTexture.loadFromFile("background1m.jpg")) {
                                Sprite optionsBackgroundSprite(optionsBackgroundTexture);
                                optionsWindow.draw(optionsBackgroundSprite);
                            }
                        }
                    }
                    else if (menuState == MenuState::Producers) {
                        //Producers Window functions
                        cout << "Producers selected!" << endl;
                        RenderWindow producersWindow(VideoMode(800, 600), "Producers", Style::Close);
                        displayProducers(producersWindow);
                    }
                    else if (menuState == MenuState::Controls) {
                        //Controls Window functions
                        cout << "Controls selected!" << endl;
                        RenderWindow controlsWindow(VideoMode(800, 600), "Controls", Style::Close);
                        displayControls(controlsWindow);
                        
                    }
                    else {
                        //Exiting
                        cout << "Exit selected!" << endl;
                        window.close();
                    }
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite);

        //Functions required to switch between menu elements
        if (font.loadFromFile("arial.ttf")) {
            Text playText("Play", font, 30);
            playText.setPosition(350.0f, 200.0f);
            playText.setFillColor(menuState == MenuState::Play ? sf::Color::Red : sf::Color::White);
            window.draw(playText);

            Text optionsText("Options", font, 30);
            optionsText.setPosition(325.0f, 250.0f);
            optionsText.setFillColor(menuState == MenuState::Options ? sf::Color::Red : sf::Color::White);
            window.draw(optionsText);

            Text producersText("Producers", font, 30);
            producersText.setPosition(300.0f, 300.0f);
            producersText.setFillColor(menuState == MenuState::Producers ? sf::Color::Red : sf::Color::White);
            window.draw(producersText);

            Text controlsText("Controls", font, 30);
            controlsText.setPosition(310.0f, 350.0f);
            controlsText.setFillColor(menuState == MenuState::Controls ? sf::Color::Red : sf::Color::White);
            window.draw(controlsText);

            Text exitText("Exit", font, 30);
            exitText.setPosition(350.0f, 400.0f);
            exitText.setFillColor(menuState == MenuState::Exit ? sf::Color::Red : sf::Color::White);
            window.draw(exitText);
        }

        window.display();
    }

    return 0;
}