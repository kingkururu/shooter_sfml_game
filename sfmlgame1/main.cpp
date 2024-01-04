//
//  main.cpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/04.
//

#include <iostream>
#include <SFML/Graphics.hpp>

void enemyPosition(float enemySpeed, int enemyCount, sf::Vector2f* enemyPos, sf::Vector2f playerPos){
    for (int i = 0; i < enemyCount; i++){
        
        float enemyToPlayerX = playerPos.x - enemyPos[i].x;
        float enemyToPlayerY = playerPos.y - enemyPos[i].y;
        
        float length = sqrt(enemyToPlayerX * enemyToPlayerX + enemyToPlayerY * enemyToPlayerY);
        
        enemyToPlayerX /= length;
        enemyToPlayerY /= length;
        
        enemyPos[i].x += enemyToPlayerX * enemySpeed;
        enemyPos[i].y += enemyToPlayerY * enemySpeed;
    }
}

int main( ){
    
    int* intArr = new int[10];
    intArr[0] = 10;
    
    
    int screenWidth = 800, screenHeight = 450;
    sf::RenderWindow window(sf::VideoMode(screenWidth,screenHeight), "sfml game tut" );
    
    sf::Vector2f rectSize = {20.0f, 10.0f};
    sf::Vector2f rectPos = {50.0f, 50.0f};
    
    sf::RectangleShape player(rectSize);
    player.setPosition(rectPos);
    player.setFillColor(sf::Color::Red);
    
    float enemySpeed = 1.0f;
    const float radiusEnemy = 10.f;
    const int enemyNum = 5;
    sf::CircleShape enemy(radiusEnemy);
    enemy.setFillColor(sf::Color::Blue);
    sf::Vector2f* enemyPos = new sf::Vector2f[enemyNum];
    
    enemy.setOutlineThickness(10.f);
    enemy.setOutlineColor(sf::Color(250, 150, 100));
    
    for (int i = 0; i < enemyNum; i++){
        enemyPos[i].x = (float)(screenWidth - 100);
        enemyPos[i].y = (float)(rand( ) % screenHeight);
        enemy.setPosition(enemyPos[i]);
    }
    
    while(window.isOpen( )){
        
        sf::Event event;
        
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                    window.close( );
                    
            if (sf::Event::KeyPressed){
                switch (event.key.code){
                    case sf::Keyboard::D:
                        rectPos.x += 8;
                        break;
                    case sf::Keyboard::A:
                        rectPos.x -= 8;
                        break;
                    case sf::Keyboard::W:
                        rectPos.y -=8;
                        break;
                    case sf::Keyboard::S:
                        rectPos.y += 8;
                        break;
                    default:
                        break;
                }
            }
            
            player.setPosition(rectPos);
            
            enemyPosition(enemySpeed, enemyNum, enemyPos, rectPos);
            
            window.clear( );
            
            window.draw(player);
            for (int i = 0; i < enemyNum; i++){
                enemy.setPosition(enemyPos[i]);
                window.draw(enemy);
            }
            
            window.display( );
        }
        
    }
    delete[] enemyPos;
}


