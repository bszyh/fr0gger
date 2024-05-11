#include "cGameBoard.h"
#include <iostream>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <string>
#include "config.h"


cGameBoard::cGameBoard() {
    
    std::string source_dir = RESOURCE_PATH;
    if( !mBackgroundTexture.loadFromFile(source_dir + "GameBoard.png")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    
    mBackgroundSprite.setTexture(mBackgroundTexture);
    
    mHeart = sf::CircleShape(20);
    mHeart.setFillColor(sf::Color(162, 59, 53));
    
    mFrogs = sf::RectangleShape(sf::Vector2f(35.0f, 35.0f));
    
    if( !mFrogsTexture.loadFromFile(source_dir + "Frogs.png")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    
    mFrogs.setTexture(&mFrogsTexture);
    
    
    mEndZone.setSize(sf::Vector2f(1320.0f, 80.0f));
    mEndZone.setPosition(0.0f, 45.0f);
    mEndZone.setFillColor(sf::Color::Transparent);

    
    // droga - sciezka 1
    mCar2.setPosition(200.f, 950.f);
    mCar2.setSpeed(5.0f);
    
    mCar3.setPosition(650.f, 950.f);
    mCar3.setSpeed(5.0f);
    
    mCar4.setPosition(1150.f, 950.f);
    mCar4.setSpeed(5.0f);

    //droga - sciezka 2
    mBus1.setPosition(0.f, 870.f);
    mBus1.setSpeed(2.0f);

    mBus2.setPosition(650.f, 870.f);
    mBus2.setSpeed(2.0f);
    
    //droga - sciezka 3
    mCar5.setPosition(0.f, 790.f);
    mCar5.setSpeed(7.0f);

    mCar6.setPosition(450.f, 790.f);
    mCar6.setSpeed(7.0f);

    mCar7.setPosition(1000.f, 790.f);
    mCar7.setSpeed(7.0f);
    
    //droga sciezka 4
    mBus3.setPosition(0.f, 710.f);
    mBus3.setSpeed(3.0f);

    mBus4.setPosition(300.f, 710.f);
    mBus4.setSpeed(3.0f);
    
    mBus5.setPosition(900.f, 710.f);
    mBus5.setSpeed(3.0f);
    
    
    //klody - sciezka 1
    mLog1.setPosition(1300.f, 225.f);
    mLog1.setSize(450.f, 65.f);
    
    //klody - sciezka 2
    mLog2.setPosition(0.f, 310.f);
    mLog2.setSpeed(5.0f);
    
    mLog4.setPosition(350.f, 310.f);
    mLog4.setSpeed(5.0f);
    
    //klody - sciezka 3
    mLog3.setPosition(950.f, 395.f);
    mLog3.setSpeed(-5.0f);
    
    mLog5.setPosition(100.f, 395.f);
    mLog5.setSize(190.f, 65.f);
    mLog5.setSpeed(-5.0f);
    
    
    cObstacleLog* mLog_wsk1 = &mLog1;
    cObstacleLog* mLog_wsk2 = &mLog2;
    cObstacleLog* mLog_wsk3 = &mLog3;
    cObstacleLog* mLog_wsk4 = &mLog4;
    cObstacleLog* mLog_wsk5 = &mLog5;

    cObstacleCar* mCar_wsk1 = &mCar1;
    cObstacleCar* mCar_wsk2 = &mCar2;
    cObstacleCar* mCar_wsk3 = &mCar3;
    cObstacleCar* mCar_wsk4 = &mCar4;
    
    cObstacleCar* mCar_wsk5 = &mCar5;
    cObstacleCar* mCar_wsk6 = &mCar6;
    cObstacleCar* mCar_wsk7 = &mCar7;


    cObstacleBus* mBus_wsk1 = &mBus1;
    cObstacleBus* mBus_wsk2 = &mBus2;
    cObstacleBus* mBus_wsk3 = &mBus3;
    cObstacleBus* mBus_wsk4 = &mBus4;
    cObstacleBus* mBus_wsk5 = &mBus5;
    
    //auta
    mBase + mCar_wsk1;
    mBase + mCar_wsk2;
    mBase + mCar_wsk3;
    mBase + mCar_wsk4;
    
    mBase2 + mCar_wsk5;
    mBase2 + mCar_wsk6;
    mBase2 + mCar_wsk7;
    
    //busy
    
    mBase_bus + mBus_wsk1;
    mBase_bus + mBus_wsk2;
    
    mBase_bus2 + mBus_wsk3;
    mBase_bus2 + mBus_wsk4;
    mBase_bus2 + mBus_wsk5;
    
    //klody
    
    mBaseLog + mLog_wsk1;
    
    mBaseLog2 + mLog_wsk2;
    mBaseLog2 + mLog_wsk4;
    
    mBaseLog3 + mLog_wsk3;
    mBaseLog3 + mLog_wsk5;
}


void cGameBoard::boardUpdate() {
    
    mBase.moveObstacles();
    mBase2.moveObstacles();
    mBase_bus.moveObstacles();
    mBase_bus2.moveObstacles();
    mBaseLog.moveObstacles();
    mBaseLog2.moveObstacles();
    mBaseLog3.moveObstacles();
}

void cGameBoard::drawBoard(sf::RenderWindow &aGameWin) {
    
    aGameWin.draw(mBackgroundSprite);
    aGameWin.draw(mEndZone);
    mWaterZone.drawWater(aGameWin);
    
    mBase.showObstacles(aGameWin);
    mBase2.showObstacles(aGameWin);
    mBase_bus.showObstacles(aGameWin);
    mBase_bus2.showObstacles(aGameWin);
    mBaseLog.showObstacles(aGameWin);
    mBaseLog2.showObstacles(aGameWin);
    mBaseLog3.showObstacles(aGameWin);
}


bool cGameBoard::handleCollision(sf::FloatRect aPlayer) {
    
    if((mBase == aPlayer)) {
        return 1;
    }
    
    if((mBase2 == aPlayer)) {
        return 1;
    }
    
    if((mBase_bus == aPlayer)) {
        return 1;
    }
    
    if((mBase_bus2 == aPlayer)) {
        return 1;
    }
    
    return 0;
}

bool cGameBoard::handleLog(sf::FloatRect aPlayer) {
    
    
    if((mBaseLog == aPlayer)) {
        mBase_wsk = &mBaseLog;
        return 1;
    }
    
    if((mBaseLog2 == aPlayer)) {
        mBase_wsk = &mBaseLog2;
        return 1;
    }
    
    if((mBaseLog3 == aPlayer)) {
        mBase_wsk = &mBaseLog3;
        return 1;
    }
    
    return 0;
}

bool cGameBoard::handleWater(sf::FloatRect aPlayer) {
    
    if(mWaterZone.isTouching(aPlayer)) {
        return 1;
    }
    
    return 0;
}

bool cGameBoard::safeFrog(sf::FloatRect aFrog) {
    
    if(mEndZone.getGlobalBounds().intersects(aFrog)) return 1;
    
    return 0;
}

cListBase* cGameBoard::getListBase() {

    return mBase_wsk;
}

void cGameBoard::drawLives(sf::RenderWindow & aGameWin, float a) {
    
    for(int i = 1; i <= a; i++) {
        mHeart.setPosition(50.0f * i, 1400.0f);
        aGameWin.draw(mHeart);
    }
}

void cGameBoard::drawFrogs(sf::RenderWindow & aGameWin, float b) {
    
    for(int i = 1; i <= b; i++) {
        mFrogs.setPosition(50.0f * i, 1343.0f);
        aGameWin.draw(mFrogs);
    }
}
