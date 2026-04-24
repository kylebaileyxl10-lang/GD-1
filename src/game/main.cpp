#include "wrapper.hpp"
#include <iostream>

int main() {
    std::cout << "Initializing Cocos2d-x Wrapper..." << std::endl;
    
    // This creates the AppDelegate using the wrapper we found
    CocosWrapper::AppDelegate app;
    
    if (app.loadDLL()) {
        void* myApp = app.create();
        app.launch(myApp);
        std::cout << "Engine Launched Successfully!" << std::endl;
    } else {
        std::cerr << "Failed to load engine components." << std::endl;
    }

    return 0;
}