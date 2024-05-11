#include "cGameManager.h"
#include "cGameState.h"

#include <cerrno>
#include <cstring>
#include <iostream>
#include <cstdlib>

cGameManager::cGameManager(sf::RenderWindow & aWin) : mWindow(aWin) {}

void cGameManager::changeState(const std::string & aNewState) {
        
    std::string rv = "";
        
    if( mCurrentStatePtr != nullptr )
        rv = mCurrentStatePtr->onExit();
    
    mCurrentStatePtr = mStateMap[aNewState];
    mCurrentStatePtr->onEnter(rv);
}

void cGameManager::run() {
    
    while (mWindow.isOpen()) {
        
        std::string currentState = mCurrentStatePtr->getStateID();
        std::string nextState = mCurrentStatePtr->getNextState();
        
        if(currentState != nextState) {
            changeState(nextState);
        }
        
        sf::Event event;
        
        
        while (mWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mWindow.close();
            
            mCurrentStatePtr->handleEvent(event, mTime.asMilliseconds());
        }
        
        //najpierw bierzemy elapsed time
        mTime = mClock.getElapsedTime();
        //nastepnie wolamy funcje UPDATE
        mCurrentStatePtr->updateModel(mTime.asMilliseconds());
        //restart the clock
        mClock.restart().asMilliseconds();
        
        mWindow.clear();
        //------------------
        
        
        mCurrentStatePtr->draw(mWindow);
        
        //------------------
        mWindow.display();
    }
}


void cGameManager::operator = (std::shared_ptr<cGameState> aState) {
   
    std::string id = aState->getStateID();
    mStateMap[id] = aState;
}
