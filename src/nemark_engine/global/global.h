#pragma once 

#include <any>
#include <string>
#include <vector>

namespace Nemark
{
    class Global
    {  public:
        template <typename T> void SetVariable(std::string name, T value);
        template <typename T> T GetVariable(std::string name);

       private:
        std::vector<std::pair<std::string, std::any>> m_globals;
    };
}