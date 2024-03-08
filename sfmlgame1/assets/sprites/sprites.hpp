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


class Sprite{
public:
    Sprite(sf::Vector2f position, sf::Vector2i size, const std::string& texturePath);
    virtual ~Sprite();
    virtual void setScreenSize(sf::Vector2i screenSize);
    virtual void updatePos();
    virtual sf::Vector2f const getSpritePos(){ return position; };
    virtual bool const getMoveState(){ return moveState; }
    virtual bool const getVisibleState(){ return visibleState; }
    sf::Sprite const returnSpritesShape(){ return *spriteCreated; }
    
protected:
    sf::Vector2f position;
    sf::Vector2i size;
    sf::Texture* skin = nullptr;
    sf::Sprite* spriteCreated;
    bool moveState = true;
    bool visibleState = true;
    sf::Vector2i screenSize;
    float speed = 0.3;
};

//player class
class Player : public Sprite{
public:
    Player(sf::Vector2f position, sf::Vector2i size, const std::string& texturePath) : Sprite(position, size, texturePath) {}
    ~Player( ) override{ };
    void updatePos() override;
    
private:
    void movePlayer();
};

//enemy class
class Enemy : public Sprite{
public:
    Enemy(sf::Vector2f position, sf::Vector2i size, const std::string& texturePath) : Sprite(position, size, texturePath) {}
    ~Enemy( ) override{ };
    void updatePos() override;
    
private:
    void moveEnemy();
};

//bullet class
class Bullet : public Sprite{
public:
    Bullet(sf::Vector2f position, sf::Vector2i size, const std::string& texturePath) : Sprite(position, size, texturePath) {}
    ~Bullet( ) override{ };
    void updatePos() override;
    
private:
    void moveBullet();
};



#endif /* fonts_hpp */
