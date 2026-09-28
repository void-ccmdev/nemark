#include "application/neditor_app.h"

int main(void)
{
    NEditorApp::Application napp;
    napp.title = "Nemark - Editor";
    return napp.run();
}