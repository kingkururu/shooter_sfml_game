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
    sf::Sprite const returnSpritesShape();
    virtual void updatePos();
    
protected:
    sf::Vector2f const getSpritePos();
    bool const outOfScreen();
    bool const getMoveState();

    sf::Vector2f position;
    sf::Vector2i size;
    sf::Texture* skin = nullptr;
    sf::Sprite* spriteCreated;
    bool moveState = true;
};

//player class
class Player : public Sprite{
public:
    Player(sf::Vector2f position, sf::Vector2i size, const std::string& texturePath) : Sprite(position, size, texturePath) {}
    ~Player( ) override{ };
    void updatePos() override;
    
private:
    
};

//enemy class
class Enemy : public Sprite{
public:
    Enemy(sf::Vector2f position, sf::Vector2i size, const std::string& texturePath) : Sprite(position, size, texturePath) {}
    ~Enemy( ) override{ };
    void updatePos() override;
    
private:
    
};

//bullet class
class Bullet : public Sprite{
public:
    Bullet(sf::Vector2f position, sf::Vector2i size, const std::string& texturePath) : Sprite(position, size, texturePath) {}
    ~Bullet( ) override{ };
    void updatePos() override;
    
private:
    
};



#endif /* fonts_hpp */
