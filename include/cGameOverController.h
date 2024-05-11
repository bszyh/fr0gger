#ifndef cGameOverController_h
#define cGameOverController_h

#include "cGameState.h"
#include <sstream>

class cGameOverController : public cGameState {
    
    std::string mNextState;
    
    sf::Texture mGameOverTexture;
    sf::Sprite mGameOverSprite;
    
    
public:
    cGameOverController();
    
    std::string getNextState() const override;
    void handleEvent (const sf::Event & aEvent, float) override;
    void updateModel(float) override;
    void draw (sf::RenderWindow & aWin) override;
    
    void onEnter(const std::string & data) override;
    std::string onExit() override;
};

#endif /* cGameOverController_h */
