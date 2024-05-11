#include "cGameOverController.h"
#include <iostream>
#include <string>
#include "config.h"

cGameOverController::cGameOverController() : cGameState("GAMEOVER") {
    
    mNextState = this->getStateID();
    
    std::string source_dir = RESOURCE_PATH;
    if( !mGameOverTexture.loadFromFile(source_dir + "GameOver.png")) {
        std::cerr << strerror(errno) << std::endl; 
        abort();
    }
    
    mGameOverSprite.setTexture(mGameOverTexture);
}

void cGameOverController::onEnter(const std::string & data) {
    
    mNextState = this->getStateID();
}


std::string cGameOverController::onExit() {
    
    return " ";
}

void cGameOverController::handleEvent (const sf::Event & aEvent, float dT) {
    
    if(aEvent.type == sf::Event::KeyPressed) {
        
        if(aEvent.key.code == sf::Keyboard::Key::Escape) {
            mNextState = "MENU";
        }
    
    }
}

void cGameOverController::updateModel(float dT) {
    
}

void cGameOverController::draw (sf::RenderWindow & aWin) {
    
    aWin.draw(mGameOverSprite);
   
}

std::string cGameOverController::getNextState() const {
    
    return mNextState;
}
