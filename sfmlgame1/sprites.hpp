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

extern float deltaTime; 
//sprite parent class
template <typename T_shape, typename T_size>
class Sprites{
public:
    Sprites(sf::Vector2f position, T_size size, sf::Color color);
    T_shape* returnShape();
    sf::Vector2f getPosition( ) const;
    virtual ~Sprites() = default;
    
protected:
    sf::Vector2f position;
    T_size size;
    sf::Color color;
    T_shape shape;
   // float deltaTime; 
};

//player class
template <typename T_shape, typename T_size>
class Player : public Sprites<T_shape, T_size>{
public:
    void changePos(sf::Event & event, const int speedBuffer);
    Player(sf::Vector2f position, T_size size, sf::Color color);
    ~Player( ) override{ };
};

//enemy class
template <typename T_shape, typename T_size>
class Enemy : public Sprites<T_shape, T_size>{
public:
    Enemy(sf::Vector2f position, T_size size, sf::Color color, float speedBuffer, float outline, sf::Color outlineColor);
    Enemy( ); 
    void moveEnemy(sf::Vector2f playerPos);
    ~Enemy( ) override{ };
    
private:
    float speedBuffer;
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
    float speed;
    const sf::Vector2i mousePos;
    sf::Vector2f direction;
    sf::Vector2f directionNorm; 
};


#endif /* sprites_hpp */
