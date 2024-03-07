//
//  sprites.cpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/07.
//
#include "sprites.hpp"

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

sf::Sprite const Sprite::returnSpritesShape(){
    return *spriteCreated;
}

void Sprite::updatePos(){
    
}

sf::Vector2f const Sprite::getSpritePos(){
    return position;
}

bool const Sprite::outOfScreen(){
    return true;
}

bool const Sprite::getMoveState(){
    return moveState;
}

//Player class
void Player::updatePos(){
    
}

//Enemy class
void Enemy::updatePos(){
    
}

//Bullet class
void Bullet::updatePos(){
    
}



