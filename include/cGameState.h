#ifndef cGameState_h
#define cGameState_h

#include <SFML/Graphics.hpp>

class cGameState {
    const std::string mMyStateID;
    
public:
    explicit cGameState(const std::string & aStateID) : mMyStateID(aStateID) {};
    
    std::string getStateID() const { return mMyStateID; };
    
    
    virtual std::string getNextState() const = 0;
    virtual void handleEvent(const sf::Event & aEvent, float) = 0;
    virtual void updateModel(float) = 0;
    virtual void draw(sf::RenderWindow & win) = 0;
    
    virtual void onEnter(const std::string & data) = 0;
    virtual std::string onExit() = 0;
    virtual ~cGameState() = default;
};


#endif /* cGameState_h */
