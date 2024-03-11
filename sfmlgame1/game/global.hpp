//
//  global.hpp
//  sfmlgame1
//
//  Created by Sunmyoung Yun on 2024/03/11.
//

#ifndef global_hpp
#define global_hpp

#include <stdio.h>

extern struct flagEvents{
    bool wPressed;
    bool aPressed;
    bool sPressed;
    bool dPressed;
    
    flagEvents() : wPressed(false), aPressed(false), sPressed(false), dPressed(false){}
} FlagEvents;

extern struct gameEvents{
    bool playerDead;
    bool enemyDead;
    
    gameEvents() : playerDead(false), enemyDead(false){}
} GameEvents;











#endif /* global_hpp */
