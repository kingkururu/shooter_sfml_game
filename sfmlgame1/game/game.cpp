//
//  game.cpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/29.
//

#include "game.hpp"

GameManager::GameManager() : screenWidth(800), screenHeight(450), deltaTime(0.0f), window(sf::VideoMode(screenWidth, screenHeight), "sfml game tut") {
    window.setFramerateLimit(30);
}

GameManager::~GameManager() {
    for (Sprite* enemy : enemySprite) {
        delete enemy;
        enemy = nullptr;
    }
    for (Sprite* bullet : bullets) {
        delete bullet;
        bullet = nullptr;
    }
    for (TextClass* textMessage : textMessages) {
        delete textMessage;
        textMessage = nullptr;
    }
    textMessages.clear();
    
    delete playerSprite;
    playerSprite = nullptr;
}

void GameManager::runGame() {
    createAssets();
    while (window.isOpen()) {
        countTime();
        handleEvents();
        update();
        draw();
    }
}

void GameManager::createAssets( ){
    //create assets here
    TextClass* textMessage = new TextClass(sf::Vector2f{0.0f, 0.0f}, 100, sf::Color::White, "/Users/student/projects/sfmlgame1/sfmlgame1/assets/fonts/arial.ttf", "hello world");
    
    playerSprite = new Sprite(sf::Vector2f{0.0f, 0.0f}, sf::Vector2i{0,0}, "/Users/student/projects/sfmlgame1/sfmlgame1/assets/sprites/texture1.png");
    
    textMessages.push_back(textMessage);
}

void GameManager::handleEvents(){
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed){
            window.close();
        }
        if (event.type == sf::Event::KeyPressed){
            switch (event.key.code){
                case sf::Keyboard::D:
                    FlagEvents.dPressed = true;
                    break;
                case sf::Keyboard::A:
                    FlagEvents.aPressed = true;
                    break;
                case sf::Keyboard::W:
                    FlagEvents.wPressed = true;
                    break;
                case sf::Keyboard::S:
                    FlagEvents.sPressed = true;
                    break;
                default:
                    break;
            }
        }
        if (event.type == sf::Event::MouseButtonPressed){
            FlagEvents.mouseClicked = true;
        }
    }
}

void GameManager::countTime(){
    sf::Time frameTime = clock.restart();
    deltaTime = frameTime.asSeconds();
    globalTime += frameTime.asSeconds(); 
}

void GameManager::update() {
    for (Sprite* enemy : enemySprite) {
        enemy->updatePos( );
    }
    for (Sprite* bullet : bullets) {
        bullet->updatePos( );
    }
    playerSprite->updatePos();
}

void GameManager::draw() {
    window.draw(*textMessages[0]->getText());
    window.draw(playerSprite->returnSpritesShape());
    for (Sprite* enemy : enemySprite) {
        window.draw(enemy->returnSpritesShape());
    }
    for (Sprite* bullet : bullets) {
        window.draw(bullet->returnSpritesShape());
    }
    window.display();
}

