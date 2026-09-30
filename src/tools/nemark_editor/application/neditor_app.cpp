#include "neditor_app.h"

#include "nemark_engine/nemark_engine.h"

Nemark::Output output;
Nemark::WindowServer windowServer;
Nemark::InputServer inputServer;
Nemark::UIServer uiServer;
Nemark::UI ui = uiServer.getUI();

using namespace NEditorApp;

bool show = true;
bool smth = false;

void updateUI()
{
    //UI
}

int Application::run()
{   
    windowServer.createWindow(500, 500, title);
    uiServer.initialize();
    uiServer.setTheme(Nemark::UI_STYLE_COLORS::CLASSIC);
    
    //Math::Vector3f vector = Math::Vector3f(); --Does not work yet :(

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