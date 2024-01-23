//
//  sprites.cpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/07.
//
#include "sprites.hpp"
#include <iostream>

//global variables
extern float deltaTime;
extern const int screenWidth, screenHeight;
static bool globalMoveState = true;

//sprite class functions
template <typename T_shape, typename T_size>
bool Sprites<T_shape, T_size>::outOfScreen(){
    float xPos = this->shape.getPosition( ).x;
    float yPos = this->shape.getPosition( ).y;
    return(xPos < 0 || xPos > screenWidth || yPos < 0 || yPos > screenHeight);
}

template <typename T_shape, typename T_size>
void Sprites<T_shape, T_size>::setMoveState(bool moveState){
    this-> moveState = moveState;
}

template <typename T_shape, typename T_size>
void Sprites<T_shape, T_size>::resetPos(){
    float xPos = this->shape.getPosition( ).x;
    float yPos = this->shape.getPosition( ).y;
    
    if (xPos < 0)
        this->position.x = 0;
    if (xPos > screenWidth)
        this->position.x = screenWidth;
    if (yPos < 0)
        this->position.y = 0;
    if (yPos > screenHeight)
        this->position.y = screenHeight;
}

template <typename T_shape, typename T_size>
Sprites<T_shape, T_size>::Sprites(sf::Vector2f position, T_size size, sf::Color color, float speed) : position(position), size(size), color(color), speed(speed){
    shape.setPosition(position);
    shape.setFillColor(color);
}

template <typename T_shape, typename T_size>
T_shape* Sprites<T_shape, T_size>::returnShape() {
    shape.setPosition(position);
    return &shape;
}

template <typename T_shape, typename T_size>
sf::Vector2f Sprites<T_shape, T_size>::getPosition( ) const {
    return position;
}

template <typename T_shape, typename T_size>
bool Sprites<T_shape, T_size>::isTouching(sf::Vector2f targetSpritePos) {
    const float epsilon = 0.1f; // Adjust this value based on your specific needs
    return (std::abs(targetSpritePos.x - this->position.x) < epsilon) || (std::abs(targetSpritePos.y - this->position.y) < epsilon);
}

//player class functions
template <typename T_shape, typename T_size>
Player<T_shape,T_size>::Player(sf::Vector2f position, T_size size, sf::Color color, float speed) : Sprites<T_shape, T_size>(position, size, color, speed){
        this->shape.setSize(this->size);
    }

template <typename T_shape, typename T_size>
void Player<T_shape, T_size>::changePos(sf::Event & event){
    if(globalMoveState){
        switch (event.key.code){
            case sf::Keyboard::D:
                this->position.x += this->speed * deltaTime;
                Sprites<T_shape, T_size>::resetPos();
                break;
            case sf::Keyboard::A:
                this->position.x -= this->speed * deltaTime;
                Sprites<T_shape, T_size>::resetPos();
                break;
            case sf::Keyboard::W:
                this->position.y -= this->speed * deltaTime;
                Sprites<T_shape, T_size>::resetPos();
                break;
            case sf::Keyboard::S:
                this->position.y += this->speed * deltaTime;
                Sprites<T_shape, T_size>::resetPos();
                break;
            default:
                break;
        }
        this->shape.setSize(this->size);
    }
}

template <typename T_shape, typename T_size>
void Player<T_shape,T_size>::setGlobalMoveState(bool enemyTouching){
    if(enemyTouching)
    globalMoveState = false;
}

//enemy class functions
template <typename T_shape, typename T_size>
Enemy<T_shape, T_size>::Enemy(sf::Vector2f position, T_size size, sf::Color color, float speed, float outline, sf::Color outlineColor) : Sprites<T_shape, T_size>(position, size, color, speed), outline(outline), outlineColor(outlineColor){
    
    this->shape.setRadius(size);
    this->position = sf::Vector2f(this->position.x - 100, static_cast<float>(rand() % static_cast<int>(this->position.y)));
    this->shape.setPosition(this ->position);
    this->shape.setFillColor(color);
    this->shape.setOutlineColor(outlineColor);
    this->shape.setOutlineThickness(outline);
}

template <typename T_shape, typename T_size>
Enemy<T_shape, T_size>::Enemy()
    : Sprites<T_shape, T_size>(sf::Vector2f(0, 0), 0.0f, sf::Color::White, 0.0f), outline(0.0f), outlineColor(sf::Color::Black) {
}

template <typename T_shape, typename T_size>
void Enemy<T_shape, T_size>::moveEnemy(sf::Vector2f playerPos) {
    if(globalMoveState){
        sf::Vector2f enemyToPlayer = playerPos - this ->position;
        float length = sqrt(enemyToPlayer.x * enemyToPlayer.x + enemyToPlayer.y * enemyToPlayer.y);
        enemyToPlayer /= length;
        this->position += enemyToPlayer * this->speed * deltaTime;
    }
}

//bullet class functions
template <typename T_shape, typename T_size>
Bullet<T_shape, T_size>::Bullet(sf::Vector2f position, T_size size, sf::Color color, float speed, sf::Vector2i mousePos) : Sprites<T_shape, T_size>(position, size, color, speed), mousePos(mousePos){
    this->shape.setRadius(size);
    this->shape.setFillColor(color);
    this->shape.setPosition(this->position);
    calculateDirVec( );
}

template <typename T_shape, typename T_size>
void Bullet<T_shape, T_size>::calculateDirVec(){
    direction = static_cast<sf::Vector2f>(mousePos) - this ->position;
    directionNorm = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);
}

template <typename T_shape, typename T_size>
void Bullet<T_shape, T_size>::moveBullet(){
    if(globalMoveState)
    this->position += directionNorm * this->speed * deltaTime;
}
