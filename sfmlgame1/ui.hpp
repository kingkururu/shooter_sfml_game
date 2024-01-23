//
//  ui.hpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/19.
//

#ifndef ui_hpp
#define ui_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Text{
public:
//    Text(const &fstream fontFile, std::string message, sf::Color color, unsigned char pixelSize);

private:
    sf::Font font;
    sf::String message;
    sf::Color color;
    unsigned char pixelSize;
//
//    textMessage.setFont(fontArial);
//    textMessage.setString("Player X (blue) wins!");
//    textMessage.setCharacterSize(24);
//    textMessage.setFillColor(sf::Color::Black);
};

class screen{
public:
    screen( );
private:
    Text text;
    sf::Window window;
 
};


#endif /* ui_hpp */
