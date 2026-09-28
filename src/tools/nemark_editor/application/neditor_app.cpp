#include "neditor_app.h"

#include "nemark_engine/nemark_engine.h"

Nemark::Output output;
Nemark::WindowServer windowServer;
Nemark::InputServer inputServer;
Nemark::UIServer uiServer;

using namespace NEditorApp;

int Application::run()
{   
    windowServer.createWindow(500, 500, title);
    uiServer.initialize();
    uiServer.setTheme(Nemark::UI_STYLE_COLORS::DARK);

    while (!windowServer.shouldWindowClose(windowServer.getCurrentWindow()))
    {
        windowServer.updateWindow(windowServer.getCurrentWindow());
        inputServer.processInput(windowServer.getCurrentWindow());
        uiServer.update();
    }

    uiServer.destroy();
    windowServer.closeWindow(windowServer.getCurrentWindow());

    return 0;
}