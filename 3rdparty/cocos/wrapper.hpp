#pragma once

// We removed windows.h because browsers don't use it
#ifdef _WIN32
    #include <windows.h>
#endif

namespace CocosWrapper {

    class AppDelegate {
    public:
        AppDelegate(const char* path = ""); 
        ~AppDelegate();

        bool loadDLL();         // Now just returns 'true' for the web
        void* create();         
        void launch(void* app); 

    private:
        // HMODULE is Windows-only, so we use void* for the web
        void* dllHandle = nullptr;
        const char* dllPath;

        typedef void* (*CreateFn)();
        typedef void  (*LaunchFn)(void*);

        CreateFn  createFn = nullptr;
        LaunchFn  launchFn = nullptr;
    };
}
