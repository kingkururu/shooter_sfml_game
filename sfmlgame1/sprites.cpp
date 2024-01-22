//
//  sprites.cpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/07.
//
#include "sprites.hpp"
#include <iostream>

//constructors
template <typename T_shape, typename T_size>
Sprites<T_shape, T_size>::Sprites(sf::Vector2f position, T_size size, sf::Color color) : position(position), size(size), color(color){
    
    //shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(color);
}

template <typename T_shape, typename T_size>
Player<T_shape,T_size>::Player(sf::Vector2f position, T_size size, sf::Color color) : Sprites<T_shape, T_size>(position, size, color){ }

template <typename T_shape, typename T_size>
Enemy<T_shape, T_size>::Enemy(sf::Vector2f position, T_size size, sf::Color color, float speedBuffer, float outline, sf::Color outlineColor) : Sprites<T_shape, T_size>(position, size, color), speedBuffer(speedBuffer), outline(outline), outlineColor(outlineColor){
    
    this->shape.setRadius(size);
    this->position = sf::Vector2f(this->position.x - 100, static_cast<float>(rand() % static_cast<int>(this->position.y)));
    this->shape.setPosition(this ->position);
    this->shape.setFillColor(color);
    this->shape.setOutlineColor(outlineColor);
    this->shape.setOutlineThickness(outline);
}

template <typename T_shape, typename T_size>
Enemy<T_shape, T_size>::Enemy()
    : Sprites<T_shape, T_size>(sf::Vector2f(0, 0), 0.0f, sf::Color::White), speedBuffer(0.0f), outline(0.0f), outlineColor(sf::Color::Black) {
}

//return shape
template <typename T_shape, typename T_size>
T_shape* Sprites<T_shape, T_size>::returnShape() {
    shape.setPosition(position);
    return &shape;
}

//return position
template <typename T_shape, typename T_size>
sf::Vector2f Sprites<T_shape, T_size>::getPosition( ) const {
    return position;
}

//change position
template <typename T_shape, typename T_size>
void Player<T_shape, T_size>::changePos(sf::Event & event, const int speedBuffer){
    switch (event.key.code){
        case sf::Keyboard::D:
            this->position.x += speedBuffer;
            break;
        case sf::Keyboard::A:
            this->position.x -= speedBuffer;
            break;
        case sf::Keyboard::W:
            this->position.y -= speedBuffer;
            break;
        case sf::Keyboard::S:
            this->position.y += speedBuffer;
            break;
        default:
            break;
    }
    this->shape.setSize(this->size);
}

template <typename T_shape, typename T_size>
void Enemy<T_shape, T_size>::moveEnemy(sf::Vector2f playerPos) {
    sf::Vector2f enemyToPlayer = playerPos - this ->position;
    float length = sqrt(enemyToPlayer.x * enemyToPlayer.x + enemyToPlayer.y * enemyToPlayer.y);
    enemyToPlayer /= length;
    this->position += enemyToPlayer * speedBuffer;
}

template <typename T_shape, typename T_size>
Bullet<T_shape, T_size>::Bullet(sf::Vector2f position, T_size size, sf::Color color, float speed) : Sprites<T_shape, T_size>(position, size, color), speed(speed){
    this->shape.setRadius(size);
    this->shape.setFillColor(color);
    this->shape.setPosition(this->position);
}

template <typename T_shape, typename T_size>
void Bullet<T_shape, T_size>::moveBullet(sf::Vector2f playerPos, sf::Vector2i mousePos){
    direction = static_cast<sf::Vector2f>(mousePos) - this ->position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length;
    this->position += direction * speed;
}
