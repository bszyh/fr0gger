#include "cObstacleBus.h"

cObstacleBus::cObstacleBus() {
    
    mObstacle.setSize(sf::Vector2f(150, 50));
    mObstacle.setFillColor(sf::Color(222, 249, 208));
    
    mPosX = 0.0f;
    mPosY = 150.0f;
    mSpeed = 5.0f;
}

void cObstacleBus::updateObstacle() {
    
    if(mSpeed > 0.0f && mPosX > 1320.f) mPosX = -150.0f;
    if(mSpeed < 0.0f && mPosX < -155.0f) mPosX = 1320.0f;
    
    this->mObstacle.setPosition(mPosX, mPosY);
}

cObstacle* cObstacleBus::Clone() {
    
    cObstacle *n = new cObstacleBus(*this);
    return n;
}
