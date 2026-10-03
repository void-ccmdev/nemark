#include "neditor_ui.h"
#include <iostream>

using namespace NEditor;

Nemark::UIServer uiServer;
Nemark::UI ui = uiServer.getUI();

void NEUI::initialize(){ uiServer.initialize(); }

void NEUI::setTheme(EditorThemes theme)
{
    if (theme == EditorThemes::DARK) { uiServer.setTheme(Nemark::UI_STYLE_COLORS::DARK); }
    if (theme == EditorThemes::LIGHT) { uiServer.setTheme(Nemark::UI_STYLE_COLORS::LIGHT); }
    if (theme == EditorThemes::CLASSIC) { uiServer.setTheme(Nemark::UI_STYLE_COLORS::CLASSIC); }
    else {
        uiServer.setTheme(Nemark::UI_STYLE_COLORS::DARK); //Set default theme if no/non-existent theme selected.
    }
}

void NEUI::startUI() { uiServer.startUI(); }
void NEUI::endUI() { uiServer.endUI(); }
void NEUI::destroyUI() { uiServer.destroy(); }

//#---Editor-UI-Elements---#
    
void AboutPage()

void HandleTopBar()
{
    if (ui.BeginMainMenuBar()) {

        if(ui.BeginMenu("File", true)) {
            //Menu items
            ui.EndMenu();
        }

        if (ui.BeginMenu("Project", true)) {
            //Menu items
            ui.EndMenu();
        }

        if (ui.BeginMenu("Editor", true)) {
            //Menu items
            ui.EndMenu();
        }

        if (ui.BeginMenu("Help", true)) {
            if (ui.MenuItem("About")) {
                //AboutPage();
            }
            ui.EndMenu();
        }

        ui.EndMainMenuBar();
    }
}

void HandleSceneTree()
{
    ui.Begin("Scene Tree", nullptr, ImGuiWindowFlags_NoCollapse);

    ui.End();
}

void HandleInspector()
{
    ui.Begin("Properties", nullptr, ImGuiWindowFlags_NoCollapse);
    
    ui.End();
}
void HandleAssetsViewer()
{
    ui.Begin("Assets Viewer", nullptr, ImGuiWindowFlags_NoCollapse);
    
    ui.End();
}

//#---Calling-UI-handlers---#

void NEUI::updateUI() {
    HandleTopBar();
    HandleInspector();
    HandleSceneTree();
    HandleAssetsViewer();
}
