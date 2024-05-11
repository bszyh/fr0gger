#include "cObstacleLog.h"
#include <iostream>

cObstacleLog::cObstacleLog() {
    
    mObstacle.setSize(sf::Vector2f(250, 65));
    mObstacle.setFillColor(sf::Color(138, 191, 109));
    
    mPosX = 0.0f;
    mPosY = 0.0f;
    mSpeed = -2.0f;
}

void cObstacleLog::updateObstacle() {
    
    if(mSpeed > 0.0f && mPosX == 1320.0f) mPosX = -350.0f;
    
    if(mSpeed < 0.0f && mPosX == -450.0f) mPosX = 1320.0f;
    
    this->mObstacle.setPosition(mPosX, mPosY);
}

cObstacle* cObstacleLog::Clone() {
    
    cObstacle *n = new cObstacleLog(*this);
    return n;
}
