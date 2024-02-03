//
//  main.cpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/04.
//

#include <iostream>

#include <SFML/Graphics.hpp>
#include "sprites.hpp"

#include "sprites.cpp"
#include "game.hpp"
//#include <cmath>


float deltaTime = 0.0f;
const int screenWidth = 800, screenHeight = 450;

int main( ){
    sf::RenderWindow window(sf::VideoMode(screenWidth,screenHeight), "sfml game tut" );
    window.setFramerateLimit(30);
    sf::Clock clock;
    float global_time = 0.0f;
    std::string timeElapsed = "";
    std::string stopMessage = "time elapsed: ";
    std::string endingMessage = "";
    bool gameEnd = false;
    //set sprites
    Player<sf::RectangleShape, sf::Vector2f>* playerSprite = new Player<sf::RectangleShape, sf::Vector2f>(sf::Vector2f{50.0f, 50.0f}, sf::Vector2f{20.0f, 10.0f}, sf::Color::Red, 140.0f);
    std::vector<Bullet<sf::CircleShape, float>*> bulletsVec;
    const int enemyNum = 3;

    Enemy<sf::CircleShape, float>* enemySprite[enemyNum];
    for(int i = 0; i < enemyNum; ++i){
        enemySprite[i] = new Enemy<sf::CircleShape, float>(sf::Vector2f{800,450}, 10.0f, sf::Color::Blue, 70.0f, 5.0f, sf::Color(250, 150, 100));
    }
    
    //when window open
    while(window.isOpen( )){
        
        sf::Event event;
        sf::Time frameTime = clock.restart();
        deltaTime = frameTime.asSeconds();
        global_time += frameTime.asSeconds();
        
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close( );
            if (event.type == sf::Event::KeyPressed)
                //                changeEvent( );
                playerSprite->changePos(event);
            if (event.type == sf::Event::MouseButtonPressed){
                Bullet<sf::CircleShape, float>* bullet = new Bullet<sf::CircleShape, float>(playerSprite->getPosition( ), 5.0f, sf::Color::White, 600.0f, sf::Mouse::getPosition(window));
                bulletsVec.push_back(bullet);
            }
        }
        for(int i = 0; i< enemyNum; ++i){
            enemySprite[i]->moveEnemy(playerSprite->getPosition());
            playerSprite->setGlobalMoveState(playerSprite->isTouching(enemySprite[i]->getPosition()));
            
            for (auto& bulletsIt : bulletsVec){
                if(bulletsIt->isTouching(enemySprite[i]->getPosition())){
                    bulletsIt->setMoveState(false);
                    enemySprite[i]->setMoveState(false);
                }
            }
        }
        
        for(auto &bullets: bulletsVec){
            bullets->moveBullet();
        }
        
        window.clear( );
        
        //draw sprites here
        window.draw(*playerSprite->returnShape());
        
        for(auto &enemySpriteit : enemySprite){
            if(enemySpriteit->getMoveState()){
                window.draw(*enemySpriteit->returnShape());
            }
        }
        
        for (auto & bulletsIt : bulletsVec){
            for (int i = 0; i < enemyNum; ++i){
                if(bulletsIt->getMoveState())
                    window.draw(*bulletsIt->returnShape( ));
            }
        }
        
        if (!gameEnd && std::all_of(enemySprite, enemySprite + enemyNum, [](const Enemy<sf::CircleShape, float>* enemy) -> bool {
                return !enemy->getMoveState();
        })){
            endingMessage = "you win";
            timeElapsed = std::to_string(global_time);
            stopMessage.append(timeElapsed);
            gameEnd = true;
        }
        
        if(!gameEnd && !playerSprite->getGlobalMoveState()){
            endingMessage = "you lose";
            timeElapsed = std::to_string(global_time);
            stopMessage.append(timeElapsed);
            gameEnd = true;
        }
            
        if(gameEnd){
            window.draw(*textSpace::makeText(stopMessage));
            window.draw(*textSpace::makeText(endingMessage, sf::Vector2f{screenWidth / 2, screenHeight / 2 }));
        }
            
        window.display( );
        
        bulletsVec.erase(std::remove_if(bulletsVec.begin(), bulletsVec.end(), [](Bullet<sf::CircleShape, float>* bullet) {
            return bullet->outOfScreen();
        }), bulletsVec.end());
        
    }
    
    //delete everything and set every pointer to null
    delete playerSprite;
    playerSprite = nullptr;
    for (int i = 0; i < enemyNum; ++i){
        delete enemySprite[i];
        enemySprite[i] = nullptr;
    }
    for (auto& bullets: bulletsVec){
        delete bullets;
        bullets = nullptr;
    }
        
    return 0;
}


