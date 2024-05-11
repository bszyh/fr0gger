#include "cListBase.h"
#include <iostream>

cListBase::cListBase() {
    
    mFirstObstacle = nullptr;
}


cListBase::~cListBase() {
    
    //std::cout << "Jestem destuktorem Bazy Listy!" << std::endl;
    cListNode *wsk = mFirstObstacle;
    
    while(wsk != nullptr) {
        delete wsk->mObstacle;
        wsk = wsk->mNextObstacle;
    }
}

void cListBase::addObstacle(cObstacle* aObstacle) {
    
    cListNode *wezel = new cListNode;
    wezel->mNextObstacle = mFirstObstacle;
    mFirstObstacle = wezel;
    
    mFirstObstacle->mObstacle = aObstacle->Clone();
}

void cListBase::showObstacles(sf::RenderWindow & aGameWin) {
    
    cListNode *wsk = mFirstObstacle;
    
    while(wsk != nullptr) {
        wsk->mObstacle->drawObstacle(aGameWin);
        wsk = wsk->mNextObstacle;
    }
}

void cListBase::moveObstacles() {
    
    cListNode *wezel = mFirstObstacle;
    
    
    while(wezel != nullptr) {
        wezel->mObstacle->moveObstacle();
        wezel->mObstacle->updateObstacle();
        wezel = wezel->mNextObstacle;
    }
}

bool cListBase::detectCollision(sf::FloatRect aPlayer) {
    
    cListNode *wezel = mFirstObstacle;
    
    
    while(wezel != nullptr) {
        if(wezel->mObstacle->getBoundingBoxObstacle().intersects(aPlayer)) return 1;
        wezel = wezel->mNextObstacle;
    }
    
    return 0;
}

float cListBase::getSpeed() {
    
    cListNode *wezel = mFirstObstacle;
    
    return wezel->mObstacle->getSpeed();
}


void cListBase::operator + (cObstacle* aObstacle) {
    
    addObstacle(aObstacle);
}


bool cListBase::operator == (sf::FloatRect aPlayer) {
    
    if(detectCollision(aPlayer)) return 1;
    
    return 0;
}
