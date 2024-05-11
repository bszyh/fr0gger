#ifndef cObstacleLog_h
#define cObstacleLog_h

#include <SFML/Graphics.hpp>
#include "cObstacle.h"

class cObstacleLog : public cObstacle {
    

public:
    cObstacleLog();
    void updateObstacle() override;
    cObstacle* Clone() override;
};


#endif /* cObstacleLog_h */
