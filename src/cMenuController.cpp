#include "cMenuController.h"
#include <iostream>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <string>
#include "config.h"

cMenuController::cMenuController() : cGameState("MENU") {
    
    mNextState = this->getStateID();
    
    std::string source_dir = RESOURCE_PATH;
    if( !mMenuTexture.loadFromFile(source_dir + "FroggerMenu.png")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    
    mMenuSprite.setTexture(mMenuTexture);
}

void cMenuController::onEnter(const std::string & data) {
    
    mNextState = this->getStateID();
}


std::string cMenuController::onExit() {
    
    return " ";
}

void cMenuController::handleEvent (const sf::Event & aEvent, float dT) {
    
    if(aEvent.type == sf::Event::KeyPressed) {
        
        if(aEvent.key.code == sf::Keyboard::Key::Enter) {
            mNextState = "GAME";
        }
    
    
    }
}

void cMenuController::updateModel(float dT) {
    
}

void cMenuController::draw (sf::RenderWindow & aWin) {
    
    aWin.draw(mMenuSprite);
}

std::string cMenuController::getNextState() const {
    
    return mNextState;
}


