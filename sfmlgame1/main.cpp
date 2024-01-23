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
#include "ui.cpp"
#include "ui.hpp"

float deltaTime = 0.0f;

int main( ){
    
    const int screenWidth = 800, screenHeight = 450;
    sf::RenderWindow window(sf::VideoMode(screenWidth,screenHeight), "sfml game tut" );
    window.setFramerateLimit(30);
    
    sf::Clock clock;

    //set sprites
    Player<sf::RectangleShape, sf::Vector2f> playerSprite(sf::Vector2f{50.0f, 50.0f}, sf::Vector2f{20.0f, 10.0f}, sf::Color::Red);
    std::vector<Bullet<sf::CircleShape, float>> bulletsVec;
    const int enemyNum = 3;
    Enemy<sf::CircleShape, float> enemySprite[enemyNum];
    for(int i = 0; i < enemyNum; ++i){
        enemySprite[i] = Enemy<sf::CircleShape, float>(sf::Vector2f{800,450}, 10.0f, sf::Color::Blue, 1.0f, 5.0f, sf::Color(250, 150, 100));
    }
    
    while(window.isOpen( )){
        sf::Event event;
        deltaTime = clock.restart( ).asSeconds( );
        
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close( );
            if (event.type == sf::Event::KeyPressed)
                playerSprite.changePos(event, 8);
            if (event.type == sf::Event::MouseButtonPressed){
                Bullet<sf::CircleShape, float> bullet(playerSprite.getPosition( ), 5.0f, sf::Color::White, 10.0f, sf::Mouse::getPosition(window));
                bulletsVec.push_back(bullet);
            }
            for(int i = 0; i< enemyNum; ++i){
                enemySprite[i].moveEnemy(playerSprite.getPosition());
            }
            
            for(auto &bullets: bulletsVec){
                bullets.moveBullet();
//                if (bullets.getPosition().x < 0 || bullets.getPosition().x > screenWidth || bullets.getPosition().y < 0 || bullets.getPosition().y > screenHeight){
//                    bulletsVec.erase(bullets);
//                }
            }
            
            window.clear( );
            
            //draw sprites here
            for (auto& bulletsIt : bulletsVec) {
                window.draw(*bulletsIt.returnShape());
            }
            window.draw(*playerSprite.returnShape());
            
            for (int i = 0; i < enemyNum; ++i){
                window.draw(*enemySprite[i].returnShape());
            }
            
            window.display( );
        }
    }
    
    return 0;
}


