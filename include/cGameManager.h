#ifndef cGameManager_h
#define cGameManager_h

#include <SFML/Graphics.hpp>
#include <memory>
#include "cGameState.h"
#include "cGameBoard.h"

class cGameManager {
    
private:
    sf::RenderWindow & mWindow;
    
    sf::Clock mClock;
    
    sf::Time mTime;
    
    std::map <std::string, std::shared_ptr<cGameState>> mStateMap;


    std::shared_ptr<cGameState> mCurrentStatePtr;
    
    cGameBoard mBoard;
    
public:
    explicit cGameManager(sf::RenderWindow & aWin);
    
    void changeState(const std::string & aNewState);
    
    void run();
    
    void operator = (std::shared_ptr<cGameState> aState);
    
    ~cGameManager() {}
    
};


#endif /* cGameManager_h */
