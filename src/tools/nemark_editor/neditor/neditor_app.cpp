#include "neditor_app.h"

#include "core/neditor_window.h"
#include "ui/neditor_ui.h"

using namespace NEditor;

int Application::run()
{   
    NEWindow window;
    NEUI ui;

    window.create(width, height, title, maximized);
    ui.initialize();
    ui.setTheme(NEUI::EditorThemes::DARK);

    while(!window.shouldClose())
    {   
        ui.startUI();

        ui.updateUI();
        window.update();
        ui.endUI();
    }

    ui.destroyUI();
    window.close();

    return 0;
}