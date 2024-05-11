#ifndef cGameController_h
#define cGameController_h

#include <SFML/Graphics.hpp>
#include "cGameState.h"
#include "cGameManager.h"
#include "cFrogPlayer.h"
#include "cObstacleCar.h"
#include "cListBase.h"
#include "cGameBoard.h"

//glowny stan gry

class cGameController : public cGameState {
    
    std::string mNextState;
    cGameBoard mBoard;
    cFrogPlayer mPlayer;
    
    int mFrogsLeft = 4;
    int mLives = 3;
    
public:
    cGameController();
    
    std::string getNextState() const override;
    void handleEvent (const sf::Event & aEvent, float) override;
    void updateModel(float) override;
    void draw (sf::RenderWindow & aWin) override;
    
    void onEnter(const std::string & data) override;
    std::string onExit() override;
};

#endif /* cGameController_h */
