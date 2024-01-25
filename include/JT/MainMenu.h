#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

enum class MenuState {
    Play,
    Options,
    Producers,
    Controls,
    Exit,
};

class OptionsState {
public:
   
    
    bool isMusicEnabled() const;
    bool musicEnabled;
    OptionsState();

    void toggleMusic();

    

    Texture& getIconTextureOn();

    Texture& getIconTextureOff();

    Sprite& getIconSprite();

private:
    
    
    Texture iconTextureOn;
    Texture iconTextureOff;
    Sprite iconSprite;
};

MenuState checkKeyPress(const Event::KeyEvent& keyEvent, MenuState currentMenuState);

MenuState handleMainMenu(RenderWindow& window, MenuState currentMenuState);

void handleOptions(RenderWindow& optionsWindow, OptionsState& optionsState);

void displayProducers(RenderWindow& producersWindow);

void displayControls(RenderWindow& controlsWindow);