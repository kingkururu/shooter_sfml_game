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
#include "global.hpp"

class GameManager {
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
    
    sf::Vector2i mouseClickedPos;
    
    Sprite* playerSprite;
    std::vector<Sprite*> enemySprite;
    std::vector<Sprite*> bullets;
    std::vector<TextClass*> textMessages;
    
    flagEvents FlagEvents;
    gameEvents GameEvents;
    
public:
    GameManager();
    ~GameManager();
    void runGame();
    sf::Vector2i getScreenSize(){ return sf::Vector2i{screenWidth, screenHeight}; }
};

#endif /* game_hpp */
