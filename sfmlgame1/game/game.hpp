//
//  game.hpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/29.
//
#ifndef game_hpp
#define game_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "sprites.hpp"
#include "sound.hpp"
#include "fonts.hpp"

class GameManager {
public:
    GameManager();
    ~GameManager();
    void runGame();

private:
    void createAssets();
    void handleEvents();
    void countTime(); 
    void update();
    void draw();

    const int screenWidth, screenHeight;
    sf::RenderWindow window;

    float deltaTime;
    float globalTime;
    sf::Clock clock;
    
    Sprite* playerSprite;
    std::vector<Sprite*> enemySprite;
    std::vector<Sprite*> bullets;
    std::vector<TextClass*> textMessages;
    
    struct flagEvents{
        bool wPressed;
        bool aPressed;
        bool sPressed;
        bool dPressed;
        bool mouseClicked;
        
        flagEvents() : wPressed(false), aPressed(false), sPressed(false), dPressed(false), mouseClicked(false) {}
        
    } FlagEvents;
};

#endif /* game_hpp */
