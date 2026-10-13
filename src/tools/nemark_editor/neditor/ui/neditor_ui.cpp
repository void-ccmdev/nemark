#include "neditor_ui.h"

#include "nemark_engine/nemark_engine.h"
#include <iostream>

#include "../project_manager/project_manager.h"

using namespace NEditor;

Nemark::UIServer uiServer;
Nemark::UI ui = uiServer.getUI();

inline Nemark::GlobalServer globalServer;
inline ProjectManager projectManager;

// New Project values
char new_name_buffer[255] {};
char new_path_buffer[255] {};

// Open Project values
char open_path_buffer[255] {};

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
    ui.Text("Create a new project");
    ui.Separator();
    ui.Text("Project name:");
    ui.InputText("Enter project name:", new_name_buffer, sizeof(new_name_buffer));
    ui.Text("Project path:");
    ui.InputText("Enter a project path:", new_path_buffer, sizeof(new_path_buffer));
    ui.Separator();
    if (ui.Button("Create project", ImVec2(200, 25))) {
        std::string nname = new_name_buffer;
        std::string npath = new_path_buffer;
        projectManager.NewProject(nname, npath);
        showNewProjectWindow = false;
    }
    ui.End();
}
bool showOpenProjectWindow = false;
void ProjectOpen() {
    ui.Begin("Open Project", &showNewProjectWindow, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoCollapse);
    ui.Text("Open a project");
    ui.Separator();
    ui.Text("Project path:");
    ui.InputText("Enter project path:", open_path_buffer, sizeof(open_path_buffer));
    ui.Separator();
    if (ui.Button("Open project", ImVec2(200, 25))) {
        std::string opath = open_path_buffer;
        projectManager.OpenProject(opath);
        showOpenProjectWindow = false;
    } 
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
                showOpenProjectWindow = true;
            }
            ui.Separator();
            if (ui.MenuItem("Close Editor", "Ctrl + Q")) {
                globalServer.SetVariable("EDITOR_SHOULD_CLOSE", true);
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

bool showErrPopUp = false;
void ErrPopUp()
{
    ui.Begin("Editor Error!", &showErrPopUp, ImGuiWindowFlags_NoDocking);

    std::string error = std::any_cast<std::string>(globalServer.GetVariable("EDITOR_ERR_POPUP_VALUE"));
    ui.TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), error.c_str());
    if (ui.Button("OK")) {
        globalServer.SetVariable("EDITOR_ERR_POPUP_VALUE", std::string(""));
        globalServer.SetVariable("EDITOR_SHOW_ERR_POPUP", false);
    }

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
    if (showNewProjectWindow) { ProjectNew(); }
    if (showOpenProjectWindow) { ProjectOpen(); }

    if (currentEditorTheme == 0) { uiServer.setTheme(Nemark::UI_STYLE_COLORS::DARK); }
    else if (currentEditorTheme == 1) { uiServer.setTheme(Nemark::UI_STYLE_COLORS::LIGHT); }
    else if (currentEditorTheme == 2) { uiServer.setTheme(Nemark::UI_STYLE_COLORS::CLASSIC); }
    else { Nemark::OutputServer output; output.printErr("Unknown theme!"); }

    if (showErrPopUp) { ErrPopUp(); }

    if (std::any_cast<bool>(globalServer.GetVariable("EDITOR_SHOW_ERR_POPUP"))) { showErrPopUp = true; }
    else { showErrPopUp = false; }
}
