#ifndef cGameBoard_h
#define cGameBoard_h

#include <SFML/Graphics.hpp>
#include "cListBase.h"
#include "cObstacle.h"
#include "cObstacleCar.h"
#include "cObstacleBus.h"
#include "cObstacleLog.h"
#include "cFrogPlayer.h"
#include "cWaterZone.h"

class cGameBoard {
    
    sf::Texture mBackgroundTexture;
    sf::Sprite mBackgroundSprite;
    
    sf::RectangleShape mEndZone;
    
    sf::CircleShape mHeart;
    
    sf::Texture mFrogsTexture;
    sf::RectangleShape mFrogs;
    
    
    cWaterZone mWaterZone;
    
    cListBase* mBase_wsk;
    
    cListBase mBase;
    cListBase mBase2;
    cListBase mBase_bus;
    cListBase mBase_bus2;
    cListBase mBaseLog;
    cListBase mBaseLog2;
    cListBase mBaseLog3;
    
    cObstacleLog mLog1;
    cObstacleLog mLog2;
    cObstacleLog mLog3;
    cObstacleLog mLog4;
    cObstacleLog mLog5;

    cObstacleBus mBus1;
    cObstacleBus mBus2;
    cObstacleBus mBus3;
    cObstacleBus mBus4;
    cObstacleBus mBus5;

    cObstacleCar mCar1;
    cObstacleCar mCar2;
    cObstacleCar mCar3;
    cObstacleCar mCar4;
    cObstacleCar mCar5;
    cObstacleCar mCar6;
    cObstacleCar mCar7;


    
public:
    cGameBoard();
    bool handleCollision(sf::FloatRect);
    bool handleLog(sf::FloatRect);
    bool handleWater(sf::FloatRect);
    bool safeFrog(sf::FloatRect);
    
    cListBase* getListBase();
    
    
    void boardUpdate();
    void drawBoard(sf::RenderWindow & aGameWin);
    void drawLives(sf::RenderWindow&, float);
    void drawFrogs(sf::RenderWindow&, float);
};

#endif /* cGameBoard_h */
