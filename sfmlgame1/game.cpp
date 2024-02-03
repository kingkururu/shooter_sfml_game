//
//  game.cpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/29.
//

#include "game.hpp"
#include <SFML/Graphics.hpp>

sf::Text* textSpace::makeText(std::string message, sf::Vector2f locationVec ){

        sf::Font* fontArial = new sf::Font;
        sf::Text* textMessage = new sf::Text;

        if(!fontArial->loadFromFile("/Users/student/Desktop/tictactoeSFML/veryfirstgame/resources/font/arial.ttf")){
            std::cerr << "Could not load font" << std::endl;
            
            delete textMessage;
            delete fontArial;
            return nullptr;
        }

        textMessage->setFont(*fontArial);
        textMessage->setString(message);
        textMessage->setCharacterSize(24);
        textMessage->setFillColor(sf::Color::White);
        textMessage->setPosition(locationVec);

        return textMessage;
    }

