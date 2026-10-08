#include "neditor_window.h"

using namespace NEditor;

void NEWindow::create(unsigned int width, unsigned int height, std::string title, bool maximized)
{
    windowServer.createWindow(width, height, title, maximized);
}

void NEWindow::update()
{
    windowServer.updateWindow(windowServer.getCurrentWindow());
}

void NEWindow::close()
{
    windowServer.closeWindow(windowServer.getCurrentWindow());
}

bool NEWindow::shouldClose()
{
    return windowServer.shouldWindowClose(windowServer.getCurrentWindow());
}

void NEWindow::setShouldClose(bool value)
{
    windowServer.setWindowShouldClose(windowServer.getCurrentWindow(), value);
}

Nemark::Window NEWindow::getNemarkWindow()
{
    return windowServer.getCurrentWindow();
}