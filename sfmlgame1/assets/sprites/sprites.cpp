//
//  sprites.cpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/07.
//
#include "sprites.hpp"
flagEvents FlagEvents;

//base class (sprite)
Sprite::Sprite(sf::Vector2f position, sf::Vector2i size, const std::string& texturePath) : position(position), size(size), skin(new sf::Texture), spriteCreated(new sf::Sprite){
    
    if(!skin->loadFromFile(texturePath)){
        std::cerr << "Erorr in loading sprite texture from: " << texturePath << std::endl;
        return;
    }
    
    spriteCreated->setTexture(*skin);
    spriteCreated->setPosition(position);
}

Sprite::~Sprite(){
    delete skin;
    delete spriteCreated;
}

void Sprite::setScreenSize(sf::Vector2i screenSize){
    this-> screenSize = screenSize;
}

void Sprite::updatePos(){
    if (position.x > screenSize.x) {
        position.x = screenSize.x;
    } else if (position.x < 0) {
        position.x = 0;
    }
    if (position.y > screenSize.y) {
        position.y = screenSize.y;
    } else if (position.y < 0) {
        position.y = 0;
    }
    spriteCreated->setPosition(position);
}

//Player class
void Player::movePlayer(){
    
    if(FlagEvents.wPressed){
//  
   }
//
    spriteCreated->setPosition(position);
    updatePos();
}

//Enemy class
void Enemy::moveEnemy(){
    spriteCreated->setPosition(position);
    updatePos( );
}

//Bullet class
void Bullet::moveBullet(){
    spriteCreated->setPosition(position);
    updatePos( );
}



