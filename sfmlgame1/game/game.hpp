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
public:
    GameManager();
    ~GameManager();
    void runGame();
    
private:
    void createAssets();
    void handleEventInput();
    void handleGameEvents();
    void freezeSprites();
    void countTime();
    void moveSprites();
    void draw();

    sf::RenderWindow window;
    sf::Clock clock;
    
    Player* playerSprite;
    std::vector<Enemy*> enemySprite;
    std::vector<Bullet*> bullets;
    std::vector<TextClass*> endMessage;
    std::string endingText;
};

#endif /* game_hpp */
