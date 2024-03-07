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
    ~Sprite();
    sf::Vector2f const getSpritePos();
    sf::Sprite const returnSpritesShape();
    void updatePos();
    
protected:
    sf::Vector2f position;
    sf::Vector2i size;
    sf::Texture* skin = nullptr;
    sf::Sprite* spriteCreated;
};

class Player : public Sprite{
    
};

class Enemy : public Sprite{
    
};

class Bullet : public Sprite{
    
};




#endif /* fonts_hpp */
