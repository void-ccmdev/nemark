#pragma once

#include <string>

namespace NEditor
{
    class Application {
        public:
        
        std::string title = "Nemark Editor";
        unsigned int height = 1280;
        unsigned int width = 720;
        bool maximized = true;

        int run();
    }; 
}