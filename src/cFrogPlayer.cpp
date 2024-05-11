#include "cFrogPlayer.h"
#include <iostream>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <string>
#include "config.h"

cFrogPlayer::cFrogPlayer() {
    
    
    mFrog.setSize(sf::Vector2f(50.0f, 50.0f));
    mFrog.setOrigin(25.0f, 25.0f);
    
    std::string source_dir = RESOURCE_PATH;
    if( !mTexture.loadFromFile(source_dir + "Frog.png")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    
    sf::Texture* wskTexture = &mTexture;
    
    mFrog.setTexture(wskTexture);
    
    mFrog_x = 635.0f;
    mFrog_y = 1300.5f;
    mStep = 80.0f;
    mSpeed = 0.0f;
}

void cFrogPlayer::moveFrog(char m) {
    
    switch (m) {

        case 'A':
            mFrog_x -= mStep;
            break;

        case 'D':
            mFrog_x += mStep;
            break;

        case 'W':
            mFrog_y -= mStep;
            break;

        case 'S':
            mFrog_y += mStep;
            break;
     }
        
}

void cFrogPlayer::moveFrogObstacle() {
    
    mFrog_x += mSpeed;
    mSpeed = 1.0f;
}

sf::FloatRect cFrogPlayer::getBoundingBox() {
    
    return mFrog.getGlobalBounds();
}

void cFrogPlayer::drawFrog(sf::RenderWindow & aGameWin) {
    
    aGameWin.draw(mFrog);
}

void cFrogPlayer::updateFrog() {

    this->mFrog.setPosition(mFrog_x, mFrog_y);
}

bool cFrogPlayer::outsideScreen() {
    
    if(mFrog_x > 1320.0f || mFrog_x < 0.0f) return 1;
    
    return 0;
}

void cFrogPlayer::resetFrog() {
    
    mFrog_x = 635.0f;
    mFrog_y = 1300.5f;
}

void cFrogPlayer::setSpeed(float aSpeed) {
    
    mSpeed = aSpeed;
}
