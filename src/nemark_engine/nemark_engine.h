#pragma once

#include <string>
#include <vector>

#include "core/window.h"
#include "core/input.h"
#include "ui/ui.h"
#include "global/global.h"
#include "filesystem/filesystem.h"

namespace Nemark
{
    class OutputServer {
        public:
            void print(std::string value);
            void println(std::string value);
            void printWarning(std::string value);
            void printErr(std::string value);

            std::vector<std::string> getOutputLog();
        private:
            std::vector<std::string> m_log;
    };

    class WindowServer {
        public:
            void createWindow(unsigned int width, unsigned int height, std::string& title, bool maximized);
            void setWindowTitle(std::string& title, Window window);
            void updateWindow(Window window);
            void closeWindow(Window window);

            bool shouldWindowClose(Window window);
            void setWindowShouldClose(Window window, bool value);

            Window getCurrentWindow();
        private:
            Window m_currentWindow;
    };

    class InputServer {
        public:
            void addEvent(Input::InputEvent newEvent);
            void processInput(Window window);
        private:
            Input::InputManager m_inputManager;
    };

    class UIServer {
        public:
            void initialize();
            void setTheme(UI_STYLE_COLORS theme);
            void startUI();
            void endUI();
            void destroy();

            UI getUI();

            UI ui;
    };

    class GlobalServer {
        public:
            void SetVariable(std::string name, std::any value);
            std::any GetVariable(std::string name) const;
            void RemoveVariable(std::string name);
        private:
            Global m_global;
    };

    class FileServer {
        public:
            File createFile(std::string& name, std::string& path);

            void writeFile(File file, std::string& content);
            void appendToFile(File file, std::string& content);
            std::string readFile(File file);
            void removeFile(File file);

        private:
            FileSystem m_fs;
    };
} // namespace Engine
