#ifndef cMenuController_h
#define cMenuController_h

#include "cGameState.h"
#include <sstream>

class cMenuController : public cGameState {
    
    std::string mNextState;
    sf::Texture mMenuTexture;
    sf::Sprite mMenuSprite;
    
public:
    cMenuController();
    
    std::string getNextState() const override;
    void handleEvent (const sf::Event & aEvent, float) override;
    void updateModel(float) override;
    void draw (sf::RenderWindow & aWin) override;
    
    void onEnter(const std::string & data) override;
    std::string onExit() override;
};

#endif /* cMenuController_h */
