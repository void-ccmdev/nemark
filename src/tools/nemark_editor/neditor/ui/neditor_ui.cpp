#include "neditor_ui.h"

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

void HandleTopBar()
{
    if (ui.BeginMainMenuBar()) {

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

    if (showAboutPage) { AboutPage(); }
    if (showEditorSettings) { EditorSettings(); }

    if (currentEditorTheme == 0) { uiServer.setTheme(Nemark::UI_STYLE_COLORS::DARK); }
    else if (currentEditorTheme == 1) { uiServer.setTheme(Nemark::UI_STYLE_COLORS::LIGHT); }
    else if (currentEditorTheme == 2) { uiServer.setTheme(Nemark::UI_STYLE_COLORS::CLASSIC); }
    else { Nemark::OutputServer output; output.printErr("Unknown theme!"); }
}
