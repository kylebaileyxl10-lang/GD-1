#include "wrapper.hpp"
#include <iostream>

namespace CocosWrapper {

    AppDelegate::AppDelegate(const char* path)
        : dllHandle(nullptr), dllPath(path) {}

    AppDelegate::~AppDelegate() {
        // FreeLibrary is Windows-only, so we do nothing here on the web
    }

    bool AppDelegate::loadDLL() {
        // On the web, we don't load DLLs, so we just pretend it worked
        std::cout << "Web environment detected: Skipping DLL load." << std::endl;
        return true; 
    }

    void* AppDelegate::create() {
        std::cout << "Creating App Instance..." << std::endl;
        return nullptr; // We return null for now to keep it simple
    }

    void AppDelegate::launch(void* app) {
        std::cout << "Launching Game Engine on Web..." << std::endl;
    }

} // namespace CocosWrapper