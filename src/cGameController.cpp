#include "cGameController.h"
#include "cGameState.h"
#include <iostream>

cGameController::cGameController() : cGameState("GAME") {
    
    mNextState = this->getStateID();
}

void cGameController::onEnter(const std::string & data) {
    
    //ustawienie stanu przy ponownym wejściu
    mNextState = this->getStateID();
    mLives = 3;
    mFrogsLeft = 4;
}

std::string cGameController::onExit() {
    
    return "";
}

void cGameController::handleEvent (const sf::Event & aEvent, float dT) {
    
    if(mLives == 0) mNextState = "GAMEOVER";
    
    if(mFrogsLeft == 0) mNextState = "WIN";
    
    if(aEvent.type == sf::Event::KeyPressed) {
    
        if(aEvent.key.code == sf::Keyboard::Escape) {
            mPlayer.resetFrog();
            mNextState = "MENU";
        }
        
        
        if(aEvent.key.code == sf::Keyboard::Key::D) {
            
            mPlayer.moveFrog('D');
        }

        if(aEvent.key.code == sf::Keyboard::Key::A) {
                
            mPlayer.moveFrog('A');
        }

        if(aEvent.key.code == sf::Keyboard::Key::W) {
                
            mPlayer.moveFrog('W');
        }

        if(aEvent.key.code == sf::Keyboard::Key::S) {
                
            mPlayer.moveFrog('S');
        }
    }
    
}

void cGameController::updateModel(float dT) {
    
    mBoard.boardUpdate();

    mPlayer.updateFrog();
    
    if(mPlayer.outsideScreen()) {
        
        mLives -= 1;
        mPlayer.resetFrog();
    }
    
    if(mBoard.handleCollision(mPlayer.getBoundingBox())) {
        
        mLives -= 1;
        mPlayer.resetFrog();
    }
    
    
    if((mBoard.handleWater(mPlayer.getBoundingBox()))) {
        
        bool isSafe = 0;
        
        if((mBoard.handleLog(mPlayer.getBoundingBox()))) {
            
            cListBase* wsk = mBoard.getListBase();
            mPlayer.setSpeed(wsk->getSpeed());
            mPlayer.moveFrogObstacle();
            isSafe = 1;
        }

        if( isSafe != 1) {
            
            mLives -= 1;
            mPlayer.resetFrog();
        }
    }
    
    if(mBoard.safeFrog(mPlayer.getBoundingBox())) {
        
        std::cout << "Frog is safe!!" << std::endl;
        mFrogsLeft -= 1;
        mPlayer.resetFrog();
    }
    
    mPlayer.updateFrog();
    
}

void cGameController::draw (sf::RenderWindow & aGameWin) {
    
    mBoard.drawBoard(aGameWin);
    mBoard.drawLives(aGameWin, mLives);
    mBoard.drawFrogs(aGameWin, mFrogsLeft);
    mPlayer.drawFrog(aGameWin);
}

std::string cGameController::getNextState() const {
    
    return mNextState;
}
