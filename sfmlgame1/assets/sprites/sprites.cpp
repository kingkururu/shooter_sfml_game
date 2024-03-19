//
//  sprites.cpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/07.
//
#include "sprites.hpp"

//base class (sprite)
Sprite::Sprite(sf::Vector2f position, sf::Vector2f size, const std::string& texturePath) : position(position), size(size), skin(new sf::Texture), spriteCreated(new sf::Sprite){
    
    if(!skin->loadFromFile(texturePath)){
        std::cerr << "Erorr in loading sprite texture from: " << texturePath << std::endl;
        return;
    }
    
    spriteCreated->setTexture(*skin);
    spriteCreated->setPosition(position);
    spriteCreated->setScale(size);
}

Sprite::~Sprite(){
    delete skin;
    delete spriteCreated;
}

void Sprite::updatePos(){
    if (position.x > GameComponents.screenWidth) {
        position.x = GameComponents.screenWidth;
    } else if (position.x < 0) {
        position.x = 0;
    }
    if (position.y > GameComponents.screenHeight) {
        position.y = GameComponents.screenHeight;
    } else if (position.y < 0) {
        position.y = 0;
    }
    spriteCreated->setPosition(position);
}

//Player class
void Player::movePlayer(){
    if(FlagEvents.wPressed){
        position.y -= speed * GameComponents.deltaTime;
    }
    if(FlagEvents.aPressed){
        position.x -= speed * GameComponents.deltaTime;
    }
    if(FlagEvents.sPressed){
        position.y += speed * GameComponents.deltaTime;
    }
    if(FlagEvents.dPressed){
        position.x += speed * GameComponents.deltaTime;
    }
    this->updatePos();
}

//Enemy class
void Enemy::moveEnemy(sf::Vector2f playerPos){
    sf::Vector2f enemyToPlayer = playerPos - position;
    float length = sqrt(enemyToPlayer.x * enemyToPlayer.x + enemyToPlayer.y * enemyToPlayer.y);
    enemyToPlayer /= length;
    position += enemyToPlayer * this->speed * GameComponents.deltaTime;
    updatePos( );
}

//Bullet class
void Bullet::calculateDirVec(){
    sf::Vector2f direction = static_cast<sf::Vector2f>(GameComponents.mouseClickedPos) - position;
    directionUnit = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);
}

void Bullet::moveBullet(){
    position += directionUnit * speed * GameComponents.deltaTime;

    if (position.x > GameComponents.screenWidth || position.x < 0 || position.y > GameComponents.screenHeight || position.y < 0) {
        visibleState = false;
    }
    spriteCreated->setPosition(position);
}



