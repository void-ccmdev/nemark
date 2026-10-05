#include "global.h"

#include "nemark_engine/nemark_engine.h"
#include <any>
#include <iostream>

using namespace Nemark;

void Global::SetVariable(std::string name, std::any value)
{
    for (auto& global : m_globals) {
        if (global.first == name) { global.second = value; return;}
    }
    m_globals.push_back( {name, value} );
}

std::any Global::GetVariable(std::string name) const
{
    for (auto& global : m_globals) {
        if (global.first == name) {
            return global.second;
        }
    }
    Nemark::OutputServer output;
    output.printErr("Can't find global variable: " + name);
    return nullptr;
}

void Global::RemoveVariable(std::string name)
{   int index = 0;
    for (auto& global : m_globals) {
        index++;
        if (global.first == name) {
            m_globals.erase(m_globals.begin() + index);
            std::cout << index << std::endl;
            return;
        }
    }
    Nemark::OutputServer output;
    output.printErr("Can't remove variable: '" + name + "' : Doesn't exist!");
}
