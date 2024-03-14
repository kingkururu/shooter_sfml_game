//
//  game.cpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/01/29.
//

#include "game.hpp"
GameManager::GameManager() : window(sf::VideoMode(GameComponents.screenHeight, GameComponents.screenWidth), "sfml game tut") {
    window.setFramerateLimit(30);
}

GameManager::~GameManager() {
    for (Enemy* enemy : enemySprite) {
        delete enemy;
        enemy = nullptr;
    }
    for (Bullet* bullet : bullets) {
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
    
   // for (int i = 0; i< GameComponents.enemyNum; i++){
        Enemy* enemy1 = new Enemy(sf::Vector2f{0.0f, 0.0f}, sf::Vector2i{0,0}, "/Users/student/projects/sfmlgame1/sfmlgame1/assets/sprites/3.png");
        enemySprite.push_back(enemy1);
  //  }
    Bullet* bullet1 = new Bullet(sf::Vector2f{0.0f, 50.0f}, sf::Vector2i{0,0}, "/Users/student/projects/sfmlgame1/sfmlgame1/assets/sprites/2.png");
    bullets.push_back(bullet1);
    
    playerSprite = new Player(sf::Vector2f{0.0f, 0.0f}, sf::Vector2i{0,0}, "/Users/student/projects/sfmlgame1/sfmlgame1/assets/sprites/1.png");
    
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
        if (event.type == sf::Event::KeyReleased){
            FlagEvents.dPressed = false;
            FlagEvents.aPressed = false;
            FlagEvents.wPressed = false;
            FlagEvents.sPressed = false;
        }
        if (event.type == sf::Event::MouseButtonPressed){
            GameComponents.mouseClickedPos = sf::Mouse::getPosition(window);
        }
    }
}

void GameManager::countTime(){
    sf::Time frameTime = clock.restart();
    GameComponents.deltaTime = frameTime.asSeconds();
    GameComponents.globalTime += frameTime.asSeconds();
}

void GameManager::update() {
    for (Sprite* enemy : enemySprite) {
        if(enemy->getMoveState())
            enemy->updatePos( );
    }
    for (Sprite* bullet : bullets) {
        if(bullet->getMoveState())
            bullet->updatePos( );
    }
    if(playerSprite->getMoveState())
        playerSprite->movePlayer();
}

void GameManager::draw() {
    window.clear();
    window.draw(playerSprite->returnSpritesShape());
    for (TextClass* text : textMessages) {
        if(text->visibleState())
        window.draw(*text->getText());
    }
    for (Sprite* enemy : enemySprite) {
        if(enemy->getVisibleState())
        window.draw(enemy->returnSpritesShape());
    }
    for (Sprite* bullet : bullets) {
        if(bullet->getVisibleState())
        window.draw(bullet->returnSpritesShape());
    }
    window.display();
}
