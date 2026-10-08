#include "neditor_input.h"

inline Nemark::InputServer inputServer;
inline Nemark::GlobalServer globalServer;

using namespace NEditor;

//--WIRE-UP-ACTIONS
void actionQuit() { globalServer.SetVariable("EDITOR_SHOULD_CLOSE", true); }

//--MAIN

void NEInput::setShortcuts()
{
    Input::InputEvent e_quit;
    {
        e_quit.name = "Editor-Quit";
        e_quit.device = Input::Device::KEYBOARD;
        e_quit.key = GLFW_KEY_Q;
        e_quit.mod.ctrl = true;
        e_quit.action = actionQuit;
    }

    inputServer.addEvent(e_quit);
}

void NEInput::processInput(Nemark::Window window)
{
    inputServer.processInput(window);
}