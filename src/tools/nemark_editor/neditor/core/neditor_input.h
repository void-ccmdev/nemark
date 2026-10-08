#pragma once

#include "nemark_engine/nemark_engine.h"

namespace NEditor
{
    class NEInput {
        public:

        void setShortcuts();
        void processInput(Nemark::Window);
    };
}