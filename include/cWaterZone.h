#ifndef cWaterZone_h
#define cWaterZone_h

#include <SFML/Graphics.hpp>

class cWaterZone {
    
    sf::RectangleShape mWater;
    sf::FloatRect mWaterBounds;
    
public:
    cWaterZone();
    sf::FloatRect getBoundBox();
    void drawWater(sf::RenderWindow & aGameWin);
    bool isTouching(sf::FloatRect);

};

#endif /* cWaterZone_h */
