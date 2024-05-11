#ifndef cFrogPlayer_h
#define cFrogPlayer_h

#include <SFML/Graphics.hpp>

class cFrogPlayer {
    
    sf::Texture mTexture;
    sf::RectangleShape mFrog;
    
    float mFrog_x;
    float mFrog_y;
    
    float mStep;
    float mSpeed;
    
public:
    cFrogPlayer();
    
    void moveFrog(char);
    void moveFrogObstacle();
    void drawFrog(sf::RenderWindow & aGameWin);
    void updateFrog();
    sf::FloatRect getBoundingBox();
    void resetFrog();
    bool outsideScreen();
    void setSpeed(float);
    
};


#endif /* cFrogPlayer_h */
