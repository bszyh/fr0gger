#include <SFML/Graphics.hpp>
#include <memory>
#include "cGameManager.h"
#include "cMenuController.h"
#include "cGameController.h"
#include "cGameOverController.h"
#include "cWinController.h"

int main(int argc, const char * argv[]) {
    
    constexpr int screen_width = 1320;
    constexpr int screen_height = 1450;
    
    sf::RenderWindow window (sf::VideoMode(screen_width, screen_height), "Project_Frogg_App");
    cGameManager manager(window);
    
    window.setVerticalSyncEnabled(true);
    
    manager = std::make_shared<cMenuController>();
    manager = std::make_shared<cGameController>();
    manager = std::make_shared<cGameOverController>();
    manager = std::make_shared<cWinController>();
    
    manager.changeState("MENU");
    
    manager.run();
    
    return 0;
}
