#pragma once

#include "nemark_engine/nemark_engine.h"

namespace NEditor
{
    class NEWindow
    { public:

        void create(unsigned int width, unsigned int height, std::string title, bool maximized);
        void update();
        void close();

        bool shouldClose();
        void setShouldClose(bool value);

        Nemark::Window getNemarkWindow();

        Nemark::WindowServer windowServer;
    };
}