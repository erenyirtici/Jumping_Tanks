#include "MainMenu.h"
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;
//Consturctor of the OptionState class
OptionsState::OptionsState() : musicEnabled(true) {}
//Music on and off
void OptionsState::toggleMusic() {
    musicEnabled = !musicEnabled;
    
}
//Checking Music Enabled
bool OptionsState::isMusicEnabled() const {
    return musicEnabled;
    
}

// Function to get the texture of the on icon
Texture& OptionsState::getIconTextureOn() {
    return iconTextureOn;
   
}
// Function to get the texture of the off icon
Texture& OptionsState::getIconTextureOff() {
    return iconTextureOff;
}

Sprite& OptionsState::getIconSprite() {
    return iconSprite;
}
// Function to check keypress events in the main menu
MenuState checkKeyPress(const Event::KeyEvent& keyEvent, MenuState currentMenuState) {
    switch (keyEvent.code) {
    case Keyboard::Up:
        if (currentMenuState == MenuState::Play) {
            return MenuState::Exit;
        }
        else if (currentMenuState == MenuState::Options) {
            return MenuState::Play;
        }
        else if (currentMenuState == MenuState::Producers) {
            return MenuState::Options;
        }
        else if (currentMenuState == MenuState::Controls) {
            return MenuState::Producers;
        }
        else {
            return MenuState::Controls;
        }
    case Keyboard::Down:
        if (currentMenuState == MenuState::Play) {
            return MenuState::Options;
        }
        else if (currentMenuState == MenuState::Options) {
            return MenuState::Producers;
        }
        else if (currentMenuState == MenuState::Producers) {
            return MenuState::Controls;
        }
        else if (currentMenuState == MenuState::Controls) {
            return MenuState::Exit;
        }
        else {
            return MenuState::Play;
        }
    case Keyboard::Enter:
        if (currentMenuState == MenuState::Controls) {
            return currentMenuState;
        }
        return currentMenuState;
    default:
        return currentMenuState;
    }
}
// Function to handle main menu events
MenuState handleMainMenu(RenderWindow& window, MenuState currentMenuState) {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            return currentMenuState;
        }
        else if (event.type == Event::KeyPressed) {
            currentMenuState = checkKeyPress(event.key, currentMenuState);
        }
    }
    return currentMenuState;
}
// Function to handle options menu events
void handleOptions(RenderWindow& optionsWindow, OptionsState& optionsState) {
    Event optionsEvent;
    

    while (optionsWindow.isOpen()) {
        while (optionsWindow.pollEvent(optionsEvent)) {
            if (optionsEvent.type == Event::Closed) {
                optionsWindow.close();
            }
            else if (optionsEvent.type == Event::KeyPressed) {
                if (optionsEvent.key.code == Keyboard::Enter) {
                    optionsState.toggleMusic();
                    
                    
                }
                else if (optionsEvent.key.code == Keyboard::Escape) {
                    optionsWindow.close();
                }
            }
        }

        optionsWindow.clear();
        //Font functions
        Font font;
        if (font.loadFromFile("arial.ttf")) {
            Text musicText("Music", font, 30);
            musicText.setPosition(300.0f, 250.0f);

            Texture optionsBackgroundTexture;
            if (optionsBackgroundTexture.loadFromFile("background1m.jpg")) {
                Sprite optionsBackgroundSprite(optionsBackgroundTexture);
                optionsWindow.draw(optionsBackgroundSprite);
            }

            optionsWindow.draw(musicText);
            
            if (optionsState.isMusicEnabled()) {
                optionsState.getIconSprite().setTexture(optionsState.getIconTextureOn());
            }
            else {
                optionsState.getIconSprite().setTexture(optionsState.getIconTextureOff());
              

            }

            optionsState.getIconSprite().setPosition(450.0f, 250.0f);
            optionsWindow.draw(optionsState.getIconSprite());
            optionsWindow.display();
        }
    }
}
// Function to display the producers window
void displayProducers(RenderWindow& producersWindow) {
    Font font;
    if (font.loadFromFile("arial.ttf")) {
        Text producer1("Eren Yirtici", font, 20);
        producer1.setPosition(299.0f, 200.0f);

        Text producer2("Umut Yilmaz", font, 20);
        producer2.setPosition(300.0f, 250.0f);

        Text producer3("Fuad Saffetoglu", font, 20);
        producer3.setPosition(295.0f, 300.0f);

        Text producer4("Yigit Efe Salgin", font, 20);
        producer4.setPosition(294.0f, 350.0f);

        while (producersWindow.isOpen()) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                producersWindow.close();
            }
            Event producersEvent;
            while (producersWindow.pollEvent(producersEvent)) {
                if (producersEvent.type == Event::Closed) {
                    producersWindow.close();
                }
            }

            producersWindow.clear();
            Texture optionsBackgroundTexture;
            if (optionsBackgroundTexture.loadFromFile("background2m.jpg")) {
                Sprite optionsBackgroundSprite(optionsBackgroundTexture);
                producersWindow.draw(optionsBackgroundSprite);
            }
            producersWindow.draw(producer1);
            producersWindow.draw(producer2);
            producersWindow.draw(producer3);
            producersWindow.draw(producer4);
            producersWindow.display();
        }
    }
}
// Function to display the controls window
void displayControls(RenderWindow& controlsWindow) {
    Font font;

    if (font.loadFromFile("arial.ttf")) {
        Text movementText("W -> UP\n A->LEFT\n S->DOWN\n D -> RIGHT", font, 20);
        movementText.setPosition(300.0f, 200.0f);
        movementText.setFillColor(Color::Red);

        Text fireText("F -> FIRE CONTROL BUTTON", font, 20);
        fireText.setPosition(300.0f, 350.0f);
        fireText.setFillColor(Color::Red);

        Text enterescapeText("ENTER -> SELECT BUTTON\n ESC -> RETURN BUTTON ", font, 20);
        enterescapeText.setPosition(300.0f, 400.0f);
        enterescapeText.setFillColor(Color::Red);

        Text snowtext("T -> SNOWBALL\n Y-> BIG BULLET", font, 20);
        snowtext.setPosition(300.0f, 450.0f);
        snowtext.setFillColor(Color::Red);



        while (controlsWindow.isOpen()) {
            Event controlsEvent;
            while (controlsWindow.pollEvent(controlsEvent)) {
                if (controlsEvent.type == Event::Closed) {
                    controlsWindow.close();
                }
                else if (controlsEvent.type == Event::KeyPressed && controlsEvent.key.code == Keyboard::Escape) {
                    controlsWindow.close();
                }
            }

            controlsWindow.clear();
            Texture controlsBackgroundTexture;
            if (controlsBackgroundTexture.loadFromFile("background3m.jpg")) {
                Sprite controlsBackgroundSprite(controlsBackgroundTexture);
                controlsWindow.draw(controlsBackgroundSprite);
            }
            controlsWindow.draw(movementText);
            controlsWindow.draw(fireText);
            controlsWindow.draw(enterescapeText);
            controlsWindow.draw(snowtext);
            controlsWindow.display();
        }
    }
}
