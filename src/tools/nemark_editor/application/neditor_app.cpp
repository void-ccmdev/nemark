#include "neditor_app.h"

#include "nemark_engine/nemark_engine.h"

Nemark::Output output;
Nemark::WindowServer windowServer;
Nemark::InputServer inputServer;
Nemark::UIServer uiServer;
Nemark::UI ui = uiServer.getUI();

using namespace NEditorApp;

void updateUI()
{
    //Some ui functions
}

int Application::run()
{   
    windowServer.createWindow(500, 500, title);
    uiServer.initialize();
    uiServer.setTheme(Nemark::UI_STYLE_COLORS::DARK);

    while (!windowServer.shouldWindowClose(windowServer.getCurrentWindow()))
    {   
        uiServer.startUI();
        windowServer.updateWindow(windowServer.getCurrentWindow());
        updateUI();
        inputServer.processInput(windowServer.getCurrentWindow());
        uiServer.endUI();
    }

    uiServer.destroy();
    windowServer.closeWindow(windowServer.getCurrentWindow());

    return 0;
}