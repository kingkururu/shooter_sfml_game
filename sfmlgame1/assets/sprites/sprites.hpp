//
//  sprites.hpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/07.
//

#ifndef sprites_hpp
#define sprites_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "global.hpp"

class Sprite{
public:
    Sprite(sf::Vector2f position, sf::Vector2f size, const std::string& texturePath);
    virtual ~Sprite();
    void updatePos();
    sf::Vector2f const getSpritePos() const { return position; };
    bool const getVisibleState() const { return this->visibleState; }
    sf::Sprite const returnSpritesShape(){ return *spriteCreated; }
    void setVisibleState(bool VisibleState){ visibleState = VisibleState; }
    
protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture* skin = nullptr;
    sf::Sprite* spriteCreated;
    bool visibleState = true;
    float speed = 80;
};

//player class
class Player : public Sprite{
public:
    Player(sf::Vector2f position, sf::Vector2f size, const std::string& texturePath) : Sprite(position, size, texturePath) {}
    ~Player( ) override{ };
    void movePlayer();
};

//enemy class
class Enemy : public Sprite{
public:
    Enemy(sf::Vector2f position, sf::Vector2f size, const std::string& texturePath) : Sprite(position, size, texturePath) {}
    ~Enemy( ) override{ };
    void moveEnemy(sf::Vector2f playerPos);
    
private:
    float speed = 100;
};

//bullet class
class Bullet : public Sprite{
public:
    Bullet(sf::Vector2f position, sf::Vector2f size, const std::string& texturePath) : Sprite(position, size, texturePath) { calculateDirVec(); }
    ~Bullet( ) override{ };
    void moveBullet();
    
private:
    void calculateDirVec();
    sf::Vector2f directionUnit;
    float speed = 500;
};



#endif /* sprites_hpp */
