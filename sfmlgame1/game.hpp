//
//  game.hpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/29.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>


namespace textSpace{
sf::Text* makeText(std::string message, sf::Vector2f locationVec = {0.0f,0.0f}); 
}

#endif /* game_hpp */
