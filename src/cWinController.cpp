#include "cWinController.h"
#include <iostream>
#include <string>
#include "config.h"

cWinController::cWinController() : cGameState("WIN") {
    
    mNextState = this->getStateID();

    std::string source_dir = RESOURCE_PATH;
    
    if( !mWinTexture.loadFromFile(source_dir + "Win.png")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    
    mWinSprite.setTexture(mWinTexture);
}

void cWinController::onEnter(const std::string & data) {
    
    mNextState = this->getStateID();
}


std::string cWinController::onExit() {
    

    return " ";
}

void cWinController::handleEvent (const sf::Event & aEvent, float dT) {
    
    if(aEvent.type == sf::Event::KeyPressed) {
        
        if(aEvent.key.code == sf::Keyboard::Key::Escape) {
            mNextState = "MENU";
        }
    
    }
}

void cWinController::updateModel(float dT) {
    
}

void cWinController::draw (sf::RenderWindow & aWin) {
    
    aWin.draw(mWinSprite);
}

std::string cWinController::getNextState() const {
    
    return mNextState;
}
