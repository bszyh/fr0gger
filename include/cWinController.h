#ifndef cWinController_h
#define cWinController_h

#include "cGameState.h"
#include <sstream>

class cWinController : public cGameState {
   
    std::string mNextState;
    
    sf::Texture mWinTexture;
    sf::Sprite mWinSprite;
    
    
public:
    cWinController();
    
    std::string getNextState() const override;
    void handleEvent (const sf::Event & aEvent, float) override;
    void updateModel(float) override;
    void draw (sf::RenderWindow & aWin) override;
    
    void onEnter(const std::string & data) override;
    std::string onExit() override;
};

#endif /* cWinController_h */
