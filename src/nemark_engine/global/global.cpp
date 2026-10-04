#include "global.h"

#include <stdexcept>
#include "nemark_engine/nemark_engine.h"

using namespace Nemark;

template <typename T> void Global::SetVariable(std::string name, T value)
{
    m_globals.push_back({name, value});
}

template <typename T> T Global::GetVariable(std::string name)
{
    for (auto& global : m_globals) {
        if (global.first == name) {
            return global.second;
        }
    }
    Nemark::OutputServer output;
    output.printErr("Global variable not found: " + name);
}