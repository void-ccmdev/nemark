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
float val = 0.1f;

float s_val = 0.1f;
float a_val = 0.1f;

const char* menu[] = {"balc", "wwdad", "Dawda", "2313"};
int current_combo = 1;

bool show_new_window = false;

void updateUI()
{
    if (ui.Begin("Hello", &show)) {
        ui.Text("Helooo!");
        ui.Checkbox("Light theme", &smth);
        ui.DragFloat("DragFloat", &val, 0.3f, 0.0f, 100.0f);
        ui.SliderFloat("Slider Float", &s_val, 0.0f, 100.0f);
        ui.SliderAngle("AngleSlider", &a_val);


        ui.Combo("SMTH", &current_combo, menu, IM_ARRAYSIZE(menu));
        ui.Checkbox("Show new Window", &show_new_window);

    }
    ui.End();

    if (show_new_window) {
        ui.Begin("New Window", &show_new_window);
        ui.Text("Heloo!!!");
        ui.End();
    }

    if (smth) {
        uiServer.setTheme(Nemark::UI_STYLE_COLORS::LIGHT);
    } else {
        uiServer.setTheme(Nemark::UI_STYLE_COLORS::DARK);
    }

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