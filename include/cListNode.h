#ifndef cListNode_h
#define cListNode_h

#include <memory>
#include <SFML/Graphics.hpp>
#include "cObstacle.h"

class cListNode {
    
public:
    cListNode* mNextObstacle;
    cObstacle* mObstacle;
    
    explicit cListNode();
    ~cListNode();
};

#endif /* cListNode_h */
