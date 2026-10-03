#include "neditor/neditor_app.h"

/*

This is the source code of https://github.com/void-ccmdev/nemark

This is the start of the Nemark Editor application.
If you're reading this, welcome to the source code and I wish you a pleasant stay.
Also if you find some nonsense in the source code, feel free to add an issue on github :)

*/ 

int main()
{
    NEditor::Application app;

    app.title = "Nemark Editor";
    app.width = 1280;
    app.height = 720;
    app.maximized = true;

    return app.run();
}