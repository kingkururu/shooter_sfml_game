//
//  sprites.hpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/07.
//

#ifndef sprites_hpp
#define sprites_hpp

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

//bool globalMoveState = true;

//sprite class
template <typename T_shape, typename T_size>
class Sprites{
public:
    Sprites(sf::Vector2f position, T_size size, sf::Color color, float speed);
    T_shape* returnShape();
    sf::Vector2f getPosition( ) const;
    bool outOfScreen( );
    void resetPos( );
    virtual ~Sprites() = default;
    void setMoveState(bool moveState);
    bool isTouching(sf::Vector2f targetSpritePos);
    
protected:
    sf::Vector2f position;
    T_size size;
    sf::Color color;
    T_shape shape;
    float speed;
    bool moveState = true;
};

//player class
template <typename T_shape, typename T_size>
class Player : public Sprites<T_shape, T_size>{
public:
    void changePos(sf::Event & event);
    Player(sf::Vector2f position, T_size size, sf::Color color, float speed);
    ~Player( ) override{ };
    /////
    void setGlobalMoveState(bool enemyTouching);
};

//enemy class
template <typename T_shape, typename T_size>
class Enemy : public Sprites<T_shape, T_size>{
public:
    Enemy(sf::Vector2f position, T_size size, sf::Color color, float speed, float outline, sf::Color outlineColor);
    Enemy( ); 
    void moveEnemy(sf::Vector2f playerPos);
    ~Enemy( ) override{ };
    
private:
    float outline;
    sf::Color outlineColor;
};

//bullet class
template <typename T_shape, typename T_size>
class Bullet : public Sprites<T_shape, T_size>{
public:
    Bullet(sf::Vector2f playerPos, T_size size, sf::Color color, float speed, sf::Vector2i mousePos);
    void moveBullet();
    ~Bullet( ) override{ }; 
    
private:
    void calculateDirVec( );
    const sf::Vector2i mousePos;
    sf::Vector2f direction;
    sf::Vector2f directionNorm; 
};


#endif /* sprites_hpp */
