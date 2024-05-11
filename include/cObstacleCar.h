#ifndef cObstacleCar_h
#define cObstacleCar_h

#include <SFML/Graphics.hpp>
#include "cObstacle.h"

class cObstacleCar : public cObstacle {
    
    
public:
    cObstacleCar();
    
    void updateObstacle() override;
    cObstacle* Clone() override;
};

#endif /* cObstacleCar_h */
