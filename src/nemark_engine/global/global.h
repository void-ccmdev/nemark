#pragma once

#include <any>
#include <string>
#include <vector>

namespace Nemark
{
    class Global
    {  public:
        void SetVariable(std::string name, std::any value);
        std::any GetVariable(std::string name) const;
        void RemoveVariable(std::string name);

       private:
        inline static std::vector<std::pair<std::string, std::any>> m_globals;
    };
}
