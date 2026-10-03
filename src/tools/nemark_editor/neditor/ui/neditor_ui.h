#pragma once

#include "nemark_engine/nemark_engine.h"

namespace NEditor
{   
    class NEUI
    { public:  
        enum EditorThemes
        {
            DARK,
            LIGHT,
            CLASSIC
        };

        void initialize();
        void setTheme(EditorThemes theme);
        void startUI();
        void updateUI();
        void endUI();
        void destroyUI();
    };
}