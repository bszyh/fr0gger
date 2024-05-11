#ifndef cListBase_h
#define cListBase_h

#include <iostream>
#include "cListNode.h"
//?
#include "cObstacle.h"

class cListBase {

public:
    
    cListNode *mFirstObstacle;
    
    cListBase();
    ~cListBase();
    
    
    void addObstacle(cObstacle* aObstacle);
    void showObstacles(sf::RenderWindow & aGameWin);
    bool detectCollision(sf::FloatRect aPlayer);
    float getSpeed();
    
    void moveObstacles();
    
    void operator + (cObstacle* aObstacle);
    bool operator == (sf::FloatRect aPlayer);
};

#endif /* cListBase_h */
