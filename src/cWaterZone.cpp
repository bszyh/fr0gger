#include "cWaterZone.h"
#include <iostream>

cWaterZone::cWaterZone() {
    
    mWater.setPosition(0.0f, 225.0f);
    mWater.setSize(sf::Vector2f(1320, 235));
    mWater.setFillColor(sf::Color(24, 52, 66));
    mWaterBounds = mWater.getGlobalBounds();
    
}

void cWaterZone::drawWater(sf::RenderWindow & aGameWin) {
    
    aGameWin.draw(mWater);
}

bool cWaterZone::isTouching(sf::FloatRect aPlayerBox) {
    
    if(mWaterBounds.intersects(aPlayerBox)) return 1;
    
    return 0;
}
