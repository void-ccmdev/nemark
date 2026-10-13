#include "project_manager.h"

#include "nemark_engine/nemark_engine.h"
#include <filesystem>
#include <iostream>

inline Nemark::FileServer fs;
inline Nemark::GlobalServer gs;
inline Nemark::OutputServer outs;

using namespace NEditor;

void ProjectManager::NewProject(std::string& name, std::string& path)
{
    fs.createFolder(name, path);
    std::filesystem::path projectPath = std::filesystem::path(path) / name;

    std::cout << projectPath.string() << std::endl;

    Nemark::File projectFile = fs.createFile(name + std::string(".neproj"), projectPath.string());
    fs.writeFile(projectFile, std::string("Nemark SDK project"));

    gs.SetVariable("EDITOR_CURRENT_PROJECT", projectPath.string());
}
void ProjectManager::OpenProject(std::string& path)
{   
    std::error_code ec;
    const std::filesystem::path dir(path);

    if (!std::filesystem::is_directory(dir, ec)) {
        if (ec) {
            outs.printErr("Couldn't check path: " + ec.message());
            gs.SetVariable("EDITOR_ERR_POPUP_VALUE", std::string("Couldn't check path: " + ec.message()));
            gs.SetVariable("EDITOR_SHOW_ERR_POPUP", true);
        } else {
            outs.printErr("Path is not a directory " + path);
            gs.SetVariable("EDITOR_ERR_POPUP_VALUE", std::string("Path is not a directory " + path));
            gs.SetVariable("EDITOR_SHOW_ERR_POPUP", true);
        }
        return;
    } 
    
    for (const auto& file : std::filesystem::directory_iterator(path))
    {
        if (file.is_regular_file() && file.path().extension() == ".neproj") {
            std::string projectPath = path;
            gs.SetVariable("EDITOR_CURRENT_PROJECT", projectPath);
            outs.println("Project path set! Path contains '.neproj'!");
            return;
        }
        outs.printErr("Couldn't locate '.neproj' file inside the given path!");
        gs.SetVariable("EDITOR_ERR_POPUP_VALUE", std::string("Couldn't locate '.neproj' file inside the given path!"));
        gs.SetVariable("EDITOR_SHOW_ERR_POPUP", true);
    }
}