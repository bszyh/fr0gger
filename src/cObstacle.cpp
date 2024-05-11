#include "cObstacle.h"

cObstacle::cObstacle() {}

//KONSTRUKTOR - LISTA INICJALIZACYJNA
cObstacle::cObstacle(float aPosX, float aPosY, float aSpeed) : mPosX(aPosX), mPosY(aPosY), mSpeed(aSpeed) {
    
}

// cObstacle::~cObstacle() {
// }

void cObstacle::moveObstacle() {
    
    mPosX += mSpeed;
}

void cObstacle::drawObstacle(sf::RenderWindow & aGameWin) {
    
    aGameWin.draw(mObstacle);
}

void cObstacle::updateObstacle() {
    
    this->mObstacle.setPosition(mPosX, mPosY);
}

void cObstacle::setPosition(float x, float y) {
    
    mPosX = x;
    mPosY = y;
}

void cObstacle::setSpeed(float speed) {
    
    mSpeed = speed;
}

float cObstacle::getSpeed() {
    
    return mSpeed;
}

cObstacle* cObstacle::Clone() {
    
    cObstacle *n = new cObstacle(*this);
    return n;
}

sf::FloatRect cObstacle::getBoundingBoxObstacle() {
    
    return this->mObstacle.getGlobalBounds();
}

void cObstacle::setSize(float x, float y) {
    
    mObstacle.setSize(sf::Vector2f(x, y));
    
}
