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

int main( ){
    
    const int screenWidth = 800, screenHeight = 450;
    sf::RenderWindow window(sf::VideoMode(screenWidth,screenHeight), "sfml game tut" );
    
    const int enemyNum = 3;
    //set sprites
    Player<sf::RectangleShape, sf::Vector2f> playerSprite(sf::Vector2f{50.0f, 50.0f}, sf::Vector2f{20.0f, 10.0f}, sf::Color::Red);
    Enemy<sf::CircleShape, float> enemySprite[enemyNum];
    for(int i = 0; i < enemyNum; ++i){
        enemySprite[i] = Enemy<sf::CircleShape, float>(sf::Vector2f{800,450}, 10.0f, sf::Color::Blue, 1.0f, 5.0f, sf::Color(250, 150, 100));
    }

    while(window.isOpen( )){
        
        sf::Event event;
        
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                    window.close( );
            if (event.type == sf::Event::KeyPressed){
                playerSprite.changePos(event, 8);
            }
    
            for(int i = 0; i< enemyNum; ++i){
                enemySprite[i].moveEnemy(playerSprite.getPosition());
            }

            window.clear( );
            
            //draw sprites here
            window.draw(*playerSprite.returnShape());
            for (int i = 0; i < enemyNum; ++i){
                window.draw(*enemySprite[i].returnShape());
            }
            
            window.display( );
        }
        
    }
}


