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

    sf::RenderWindow window;
    sf::Clock clock;
    
    Player* playerSprite;
    std::vector<Enemy*> enemySprite;
    std::vector<Bullet*> bullets;
    std::vector<TextClass*> textMessages;

public:
    GameManager();
    ~GameManager();
    void runGame();
    sf::Vector2i getScreenSize(){ return sf::Vector2i{0, 0}; }
};

#endif /* game_hpp */
