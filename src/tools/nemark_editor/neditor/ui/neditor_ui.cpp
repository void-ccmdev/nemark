#include "neditor_ui.h"
#include "nemark_engine/nemark_engine.h"
#include <iostream>

using namespace NEditor;

Nemark::UIServer uiServer;
Nemark::UI ui = uiServer.getUI();

inline Nemark::GlobalServer globalServer;

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

bool showEditorSettings = false;
const char* editorThemes[] = {"Dark", "Light", "Classic"};
int currentEditorTheme = 0;
void EditorSettings()
{
    ui.Begin("EditorSettings", &showEditorSettings, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoCollapse);
    ui.SeparatorText("Appearance");
    ui.Combo("Theme", &currentEditorTheme, editorThemes, 3);
    //std::cout << currentEditorTheme << std::endl;
    ui.End();
}

bool showAboutPage = false;
void AboutPage()
{
    ui.Begin("About Nemark Editor", &showAboutPage, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoCollapse);
    ui.Text("hii");
    ui.End();
}
bool showNewProjectWindow = false;
void ProjectNew() {
    ui.Begin("New Project", &showNewProjectWindow, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoCollapse);
    ui.End();
}

bool showSceneTreePanel = true;
bool showInspectorPanel = true;
bool showAssetsViewerPanel = true;

void HandleTopBar()
{
    if (ui.BeginMainMenuBar()) {
        if (ui.BeginMenu("Nemark")) {
            if (ui.MenuItem("New Project")) {
                showNewProjectWindow = true;
            }
            if (ui.MenuItem("Open Project")) {

            }
            ui.Separator();
            if (ui.MenuItem("Close Editor")) {

            }
            ui.EndMenu();
        }

        if(ui.BeginMenu("File")) {
            //Menu items
            ui.EndMenu();
        }

        if (ui.BeginMenu("Project")) {
            //Menu items
            ui.EndMenu();
        }

        if (ui.BeginMenu("Editor")) {
            if (ui.MenuItem("Editor Settings")) {
                showEditorSettings = true;
            }
            if (ui.BeginMenu("Panels")) {
                ui.MenuItem("Scene Tree", NULL, &showSceneTreePanel, true);
                ui.MenuItem("Inspector", NULL, &showInspectorPanel, true);
                ui.MenuItem("Asset Viewer", NULL, &showAssetsViewerPanel, true);
                ui.EndMenu();
            }
            ui.EndMenu();
        }

        if (ui.BeginMenu("Help")) {
            if (ui.MenuItem("About")) {
                showAboutPage = true;
            }
            ui.EndMenu();
        }

        ui.EndMainMenuBar();
    }
}

void HandleSceneTree()
{
    if (showSceneTreePanel) {
        ui.Begin("Scene Tree", nullptr, ImGuiWindowFlags_NoCollapse);

        ui.End();
    }
}

void HandleInspector()
{
    if (showInspectorPanel) {
        ui.Begin("Properties", nullptr, ImGuiWindowFlags_NoCollapse);

        ui.End();
    }
}
void HandleAssetsViewer()
{
    if (showAssetsViewerPanel) {
        ui.Begin("Assets Viewer", nullptr, ImGuiWindowFlags_NoCollapse);

        ui.End();
    }
}



//#---Calling-UI-handlers---#

void NEUI::updateUI() {
    HandleTopBar();

    HandleInspector();
    HandleSceneTree();
    HandleAssetsViewer();

    if (showAboutPage) { AboutPage(); }
    if (showEditorSettings) { EditorSettings(); }
    if (showNewProjectWindow) { ProjectNew(); }

    if (currentEditorTheme == 0) { uiServer.setTheme(Nemark::UI_STYLE_COLORS::DARK); }
    else if (currentEditorTheme == 1) { uiServer.setTheme(Nemark::UI_STYLE_COLORS::LIGHT); }
    else if (currentEditorTheme == 2) { uiServer.setTheme(Nemark::UI_STYLE_COLORS::CLASSIC); }
    else { Nemark::OutputServer output; output.printErr("Unknown theme!"); }
}
