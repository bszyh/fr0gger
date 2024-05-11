#ifndef cObstacle_h
#define cObstacle_h

#include <SFML/Graphics.hpp>



class cObstacle {
    
protected:
    
    sf::RectangleShape mObstacle;
    
    float mPosX;
    float mPosY;
    
    float mSpeed;
    
public:
    cObstacle();
    cObstacle(float, float, float);
    virtual ~cObstacle() {};
    
    void setPosition(float, float);
    void setSpeed(float);
    void setSize(float, float);
    float getSpeed();
    void moveObstacle();
    void drawObstacle(sf::RenderWindow & aGameWin);
    
    //FUNKCJA WIRTUALNA
    virtual void updateObstacle();
    virtual cObstacle* Clone();
    
    sf::FloatRect getBoundingBoxObstacle();
};

#endif /* cObstacle_h */
