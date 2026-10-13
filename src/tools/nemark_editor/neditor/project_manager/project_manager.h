#pragma once

#include <string>

namespace NEditor
{
    class ProjectManager
    {   
    public:

        void NewProject(std::string& name, std::string& path);
        void OpenProject(std::string& path);
    };  
}