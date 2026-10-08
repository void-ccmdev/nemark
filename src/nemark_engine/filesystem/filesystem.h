#pragma once

#include <string>

namespace Nemark
{   
    class File {
    public:
        std::string name;
        std::string path;
    };

    class FileSystem {
    public:
        File createFile(std::string& name, std::string& path);

        void writeFile(File file, std::string& content);
        void appendToFile(File file, std::string& content);
        std::string readFile(File file);
        void removeFile(File file);

        void createFolder(std::string& name, std::string& path);
        void removeFolder(std::string& path);
    };
}