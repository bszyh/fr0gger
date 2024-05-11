#include "cObstacleCar.h"


cObstacleCar::cObstacleCar() {
    
    mObstacle.setSize(sf::Vector2f(90, 50));
    mObstacle.setFillColor(sf::Color(138, 191, 109));
    
    mPosX = 0.0f;
    mPosY = 950.0f;
    mSpeed = 5.0f;
    
}


void cObstacleCar::updateObstacle() {
    
    if(mSpeed > 0.0f && mPosX > 1320.f) mPosX = -150.0f;
    if(mSpeed < 0.0f && mPosX < -155.0f) mPosX = 1320.0f;

    this->mObstacle.setPosition(mPosX, mPosY);
}

cObstacle* cObstacleCar::Clone() {
    
    cObstacle *n = new cObstacleCar(*this);
    return n;
}
