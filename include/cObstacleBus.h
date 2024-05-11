#ifndef cObstacleBus_h
#define cObstacleBus_h

#include "cObstacle.h"

class cObstacleBus : public cObstacle {
    
public:
    cObstacleBus();
    void updateObstacle() override;
    cObstacle* Clone() override;
};


#endif /* cObstacleBus_h */
