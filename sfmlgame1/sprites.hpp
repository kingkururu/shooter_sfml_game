//
//  sprites.hpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/07.
//

#ifndef sprites_hpp
#define sprites_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <string>

//sprite parent class
template <typename T_shape, typename T_size>
class Sprites{
public:
    Sprites(sf::Vector2f position, T_size size, sf::Color color);
    
    T_shape* returnShape();
    
    sf::Vector2f getPosition( ) const;
    
protected:
    sf::Vector2f position;
    T_size size;
    sf::Color color;
    T_shape shape; 
};

//player class
template <typename T_shape, typename T_size>
class Player : public Sprites<T_shape, T_size>{
public:
    void changePos(sf::Event & event, const int speedBuffer);
    Player(sf::Vector2f position, T_size size, sf::Color color);
};

//enemy class
template <typename T_shape, typename T_size>
class Enemy : public Sprites<T_shape, T_size>{
public:
    Enemy(sf::Vector2f position, T_size size, sf::Color color, float speedBuffer, float outline, sf::Color outlineColor);
    Enemy( ); 
    void moveEnemy(sf::Vector2f playerPos);
    
private:
    float speedBuffer;
    float outline;
    sf::Color outlineColor;
};

#endif /* sprites_hpp */
