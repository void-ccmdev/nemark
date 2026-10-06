#include "nemark_engine.h"

#include <any>
#include <iostream>
#include <string>
#include <vector>

using namespace Nemark;

/////////////////////////
/////// -OUTPUT- ////////
/////////////////////////

void OutputServer::print(std::string value) { std::cout << value.c_str(); m_log.push_back(value); }
void OutputServer::println(std::string value) { std::cout << value.c_str() << std::endl; m_log.push_back(value + "\n"); }
void OutputServer::printErr(std::string value) { std::cerr << "Error: " << value.c_str() << std::endl; m_log.push_back("Error: " + value + "\n"); }
void OutputServer::printWarning(std::string value) { std::cout << "Warning: " << value.c_str() << std::endl; m_log.push_back("Warning: " + value + "\n"); }

std::vector<std::string> OutputServer::getOutputLog() { return m_log; }

/////////////////////////
/////// -WINDOW- ////////
/////////////////////////

void WindowServer::createWindow(unsigned int width, unsigned int height, std::string& title, bool maximized)
{
    Window window;
    window.create(width, height, title, maximized);
    m_currentWindow = window;
}
void WindowServer::setWindowTitle(std::string& title, Window window) { window.setTitle(title); }
void WindowServer::closeWindow(Window window) { window.close(); }
void WindowServer::updateWindow(Window window) { window.update(); window.pollEvents(); }
bool WindowServer::shouldWindowClose(Window window) { return window.shouldClose(); }
void WindowServer::setWindowShouldClose(Window window, bool value) { window.setShouldClose(value); }

Window WindowServer::getCurrentWindow() { return m_currentWindow; }

/////////////////////////
/////// -INPUT- /////////
/////////////////////////

void InputServer::addEvent(Input::InputEvent newEvent) { m_inputManager.addEvent(newEvent); }
void InputServer::processInput(Window window) { m_inputManager.processInput(window.getGlfwWindow()); }

/////////////////////////
///////   -UI-  /////////
/////////////////////////

void UIServer::initialize() { ui.initUserInterface(); }
void UIServer::setTheme(UI_STYLE_COLORS theme) { ui.setStyleColors(theme); }
void UIServer::startUI() { ui.startUserInterface(); }
void UIServer::endUI() { ui.endUserInterface(); }
void UIServer::destroy() { ui.destroyUserInterface(); }

UI UIServer::getUI() { return ui; }

/////////////////////////
/////// -GLOBAL- ////////
/////////////////////////

void GlobalServer::SetVariable(std::string name, std::any value) { m_global.SetVariable(name, value); }
std::any GlobalServer::GetVariable(std::string name) const { return m_global.GetVariable(name); }
void GlobalServer::RemoveVariable(std::string name) { m_global.RemoveVariable(name); }

/////////////////////////
///////  -FILES-  ///////
/////////////////////////

File FileServer::createFile(std::string& name, std::string& path) { return m_fs.createFile(name, path); }
void FileServer::writeFile(File file, std::string& content) { m_fs.writeFile(file, content); }
void FileServer::appendToFile(File file, std::string& content) { m_fs.appendToFile(file, content); }
std::string FileServer::readFile(File file) { return m_fs.readFile(file); }
void FileServer::removeFile(File file) { m_fs.removeFile(file); }